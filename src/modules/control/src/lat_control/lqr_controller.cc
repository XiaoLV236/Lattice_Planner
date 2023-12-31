#include "lqr_control.h"

namespace dust {
namespace control {

lqrControl::lqrControl(const double kp, const double ki, const double kd) : controller(kp,ki,kd)
{
    // 纵向速度
    vx = 0.1;
    // 横向速度
    vy = 0;

    // 前轮侧偏刚度
    cf = -321972.05;
    // 后轮侧偏刚度
    cr = -321972.05;

    m = 1696;

    // 最大纵向加速度
    max_lateral_acceleration = 2.0;
    // 最大制动减速度
    standstill_acceleration = -3.0;
    // 轴距
    wheel_base = 2.9187;
    // 前轴中心到质心的距离
    a = 1.3433;
    // 后轴中心到质心的距离
    b = 1.5754;

    // 车辆绕z轴转动的转动惯量
    Iz = 2858.5134;

    // 轮胎最大转角(rad)，暂时没用上
    wheel_max_degree = 0.6;
}


double lqrControl::calculateCmd(const std::vector<RefPoint>& targetPath, const msg_gen::gps &gps) {
    double car_yaw = gps.oriZ;
    this->vx = gps.velX * std::cos(car_yaw) + gps.velY * std::sin(car_yaw);
    this->vy = gps.velY * std::cos(car_yaw) - gps.velX * std::sin(car_yaw);
    std::cout << "vehicle_cor vy: " << this->vy << std::endl;
    //  变量再分配
    std::vector<std::pair<double, double>> trj_point_array;
	for (auto& Point : targetPath) {
		trj_point_array.emplace_back(Point.x, Point.y);
	}
	std::vector<double> trj_thetas;
	for (auto& Point : targetPath) {
		trj_thetas.push_back(Point.theta);
	}
	std::vector<double> trj_kappas;
	for (auto& Point : targetPath) {
		trj_kappas.push_back(Point.kappa);
	}
	
	double currentPositionX = gps.posX;
	double currentPositionY = gps.posY;
	double out_angle = theta_angle(trj_point_array, trj_thetas, trj_kappas, currentPositionX, currentPositionY, car_yaw);
    return out_angle;
}

double lqrControl::theta_angle(const std::vector<std::pair<double, double>>& trj_point_array, std::vector<double>& trj_thetas,
	std::vector<double>& trj_kappas, double currentPositionX, double currentPositionY, double car_yaw)
{
    int index = 0;
    double min_dis = (std::numeric_limits<int>::max)();
    for (int i = 0; i < trj_point_array.size(); ++i) {
        double dis = pow(trj_point_array[i].first - currentPositionX, 2) + pow(trj_point_array[i].second - currentPositionY, 2);
        if (dis < min_dis) {
            min_dis = dis;
            index = i;
        }
    }

	std::array<double, 5> err_k = cal_err_k(trj_point_array, trj_thetas, trj_kappas, currentPositionX, currentPositionY, car_yaw, index);
	Eigen::Matrix<double, 1, 4> k = cal_k(err_k);

	double forword_angle = cal_forword_angle(k, err_k);
	double angle = cal_angle(k, forword_angle, err_k, trj_kappas, index);
	return angle;
}


std::array<double, 5> lqrControl::cal_err_k(const std::vector<std::pair<double, double>>& trj_point_array, 
    std::vector<double>& trj_thetas, std::vector<double>& trj_kappas, double current_post_x, 
    double current_post_y, double car_yaw, int &index)
{   
    current_post_x = current_post_x + this->vx*0.3*std::cos(car_yaw) - this->vy*0.3*std::sin(car_yaw);
    current_post_y = current_post_y + this->vy*0.3*std::cos(car_yaw) + this->vx*0.3*std::sin(car_yaw);

    std::array<double, 5> err_k;
    
    // 找到index后，开始求解投影点
    Eigen::Matrix<double, 2, 1> tor;
    tor << cos(trj_thetas[index]), sin(trj_thetas[index]);
    Eigen::Matrix<double, 2, 1> nor;
    nor << -sin(trj_thetas[index]), cos(trj_thetas[index]);

    // Eigen::Vector2f d_err;
    Eigen::Matrix<double, 2, 1> d_err;
    d_err << current_post_x - trj_point_array[index].first, current_post_y - trj_point_array[index].second;
    double phi = car_yaw;

    // nor.transpose()对nor转置
    double ed = nor.transpose() * d_err;
    
    // std::cout << "横向： " << ed << std::endl;

    double es = tor.transpose() * d_err;
    // std::cout << "纵向： " << es << std::endl;

    // 投影点的threat角度
    double projection_point_threat = trj_thetas[index] + trj_kappas[index+2] * es;

    // double phi = trj_thetas[index];
    double ed_d = vy * cos(phi - projection_point_threat) +
        vx * sin(phi - projection_point_threat);
    // 计算ephi
     double ephi = sin(phi - projection_point_threat);
    //double ephi = phi - projection_point_threat;

    // 计算s_d
    double s_d = (vx * cos(phi - projection_point_threat) -
        vy * sin(phi - projection_point_threat)) /
        (1 - trj_kappas[index] * ed);
    double phi_d = this->vx * trj_kappas[index];
    double ephi_d = phi_d - trj_kappas[index] * s_d;

    // 计算投影点曲率k
    double projection_point_curvature = trj_kappas[index];

    err_k[0] = ed;
    err_k[1] = ed_d;
    err_k[2] = ephi;
    err_k[3] = ephi_d;
    err_k[4] = projection_point_curvature;

    return err_k;
}


Eigen::Matrix<double, 1, 4> lqrControl::cal_k(std::array<double, 5> err_k)
{
    Eigen::Matrix4d A;
    A << 0, 1, 0, 0,
        0, (cf + cr) / (m * vx), -(cf + cr) / m, (a * cf - b * cr) / (m * vx),
        0, 0, 0, 1,
        0, (a * cf - b * cr) / (Iz * vx), -(a * cf - b * cr) / Iz, (a * a * cf + b * b * cr) / (Iz * vx);

    // Eigen::Vector4f B;
    Eigen::Matrix<double, 4, 1> B;
    B << 0, -cf / m, 0, -a * cf / Iz;

    // // 设置成单位矩阵
    Eigen::Matrix4d Q;
    Q.setIdentity(4, 4);
    Q(0, 0) = 25;
    Q(1, 1) = 3;
    Q(2, 2) = 10;
    Q(3, 3) = 4;

    Eigen::Matrix<double, 1, 1> R;
    R(0, 0) = 15.0;
    Eigen::Matrix<double, 1, 4> k = cal_dlqr(A, B, Q, R);

    return k;
}


Eigen::Matrix<double, 1, 4> lqrControl::cal_dlqr(Eigen::Matrix4d A, Eigen::Matrix<double, 4, 1> B,
    Eigen::Matrix4d Q, Eigen::Matrix<double, 1, 1> R)
{
    // 设置最大循环迭代次数
    int numLoop = 200;
    // 设置目标极小值
    double minValue = 10e-10;
    Eigen::Matrix4d p_old;
    p_old = Q;// p取初值

    // 离散化状态方程
    double ts = 0.001;
    Eigen::Matrix4d eye;
    eye.setIdentity(4, 4);

    Eigen::Matrix4d Ad;
    Ad = (eye - ts * 0.5 * A).inverse() * (eye + ts * 0.5 * A);
    Eigen::Matrix<double, 4, 1> Bd;
    Bd = B * ts;
    for (int i = 0; i < numLoop; i++)
    {
        // B.inverse()求逆
        Eigen::Matrix4d p_new = Ad.transpose() * p_old * Ad -
            Ad.transpose() * p_old * Bd *
            (R + Bd.transpose() * p_old * Bd).inverse() *
            Bd.transpose() * p_old * Ad +
            Q;
        if (fabs((p_new - p_old).maxCoeff()) < minValue)
        {
            p_old = p_new;
            break;
        }
        p_old = p_new;
    }
    Eigen::Matrix<double, 1, 4> k;
    // Eigen::RowVector4f;
    // 当两个超出范围的浮点数（即INF）进行运算时，运算结果会成为NaN。
    k = (R + Bd.transpose() * p_old * Bd).inverse() * Bd.transpose() * p_old * Ad;
    return k;
}

double lqrControl::cal_forword_angle(Eigen::Matrix<double, 1, 4> k,
    std::array<double, 5> err_k)
{
    double k3 = k[2];
    // 不足转向系数
    double kv = a * m / (cr * wheel_base) - b * m / (cf * wheel_base);

    //投影点的曲率final_path.k[index]
    double point_curvature = err_k[4];
    double forword_angle =
        1.5 * (wheel_base * point_curvature + kv * vx * vx * point_curvature -
        k3 * (b * point_curvature + a * m * vx * vx * point_curvature / cr / (a + b)));
    return forword_angle;
}

double lqrControl::cal_angle(Eigen::Matrix<double, 1, 4> k, double forword_angle,
    std::array<double, 5> err_k, std::vector<double>& trj_kappas, int index)
{
    Eigen::Matrix<double, 4, 1> err;
    err << err_k[0], err_k[1], err_k[2], err_k[3];

    double angle = (-k * err + forword_angle) * 180  / M_PI;

    // if (angle > 135) {
    //     angle = 135;
    // }
    // else if (angle < -135) {
    //     angle = -135;
    // }
    return angle;
}

} // control
} // dust