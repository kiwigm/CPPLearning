#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class point
{
public:
    point(double a, double b, double c);
    void central_symmetry();//中心对称
    void axial_symmetry();//轴对称
    void plane_symmetry();//平面对称
    double to_point(double a, double b, double c);//点到点距离
    double to_line(point *point1, point *point2);//点到直线距离
    double to_plane(point *point1, double A, double B, double C);//点到平面距离
private:
    //三维坐标值
    double x;
    double y;
    double z;
};

point::point(double a, double b, double c)
{
    x = a;
    y = b;
    z = c;
}

//中心对称
void point::central_symmetry()
{
    cout << "点(" << x << "," << y << "," << z << ")关于原点中心对称的点的坐标：\n" << "点(" << -x << "," << -y << "," << -z << ")" << endl;
}

//轴对称
void point::axial_symmetry()
{
    cout << "点(" << x << "," << y << "," << z << ")三个坐标轴对称的点的坐标：" << endl;
    cout << "x轴  |点(" << x << "," << -y << "," << -z << ")" << endl;
    cout << "y轴  |点(" << -x << "," << y << "," << -z << ")" << endl;
    cout << "z轴  |点(" << -x << "," << -y << "," << z << ")" << endl;
}

//平面对称
void point::plane_symmetry()
{
    cout << "点(" << x << "," << y << "," << z << ")关于三个坐标轴平面对称的点的坐标：" << endl;
    cout << "x_y平面  |点(" << x << "," << y << "," << -z << ")" << endl;
    cout << "x_z平面  |点(" << x << "," << -y << "," << z << ")" << endl;
    cout << "y_z平面  |点(" << -x << "," << y << "," << z << ")" << endl;
}

//点到点距离
double point::to_point(double a, double b, double c)
{
    double distance;
    //cout << x << y << z << endl;
    //cout << a << b << c << endl;
    distance = sqrt((x - a)*(x - a) + (y - b)*(y - b) + (z - c)*(z - c));
    //cout << distance << endl;
    return distance;
}

//点到直线距离
double point::to_line(point *point1, point *point2)
{
    double distance;
    double l1 = sqrt((point1->x - point2->x)*(point1->x - point2->x) + (point1->y - point2->y)*
                                                                       (point1->y - point2->y) + (point1->z - point2->z)*(point1->z - point2->z));
    double l2 = sqrt((point1->x - x)*(point1->x - x) + (point1->y - y)*
                                                       (point1->y - y) + (point1->z - z)*(point1->z - z));
    double l3 = sqrt((x - point2->x)*(x - point2->x) + (y - point2->y)*
                                                       (y - point2->y) + (z - point2->z)*(z - point2->z));
    double cos = (l1*l1 + l2 * l2 - l3 * l3) / (2 * l1*l2);
    distance = l2 * sqrt(1 - cos * cos);
    return distance;
}

//点到平面距离
double point::to_plane(point *point1, double A, double B, double C)
{
    double distance;
    double D;
    D = -A * point1->x - B * point1->y - C * point1->z;
    distance = abs(A*x + B * y + C * z + D) / sqrt(A*A + B * B + C * C);
    return distance;
}

int main()
{
    cout << "***** 欢迎来到点类 *****" << endl;

    cout << "1.关于原点中心对称的点的坐标" << endl;
    cout << "2.关于三个坐标轴对称的点的坐标" << endl;
    cout << "3.关于三个坐标轴平面对称的点的坐标" << endl;
    cout << "4.计算点到点距离" << endl;
    cout << "5.计算点到直线距离" << endl;
    cout << "6.计算点到平面距离" << endl;
    cout << "7.退出程序" << endl;
    cout << "***********************\n" << endl;

    double x;
    double y;
    double z;
    cout << "请输入你要新创造的点的三维坐标：" << endl;
    cin >> x >> y >> z;
    point new_point(x, y, z);
    cout << "\n***           新的点诞生了           ***" << endl;
    int flag;
    while (true)
    {
        cout << "\n请选择功能：";
        cin >> flag;
        if (flag == 1)
        {
            //中心对称
            new_point.central_symmetry();
        }
        else if (flag == 2)
        {
            //轴对称
            new_point.axial_symmetry();
        }
        else if (flag == 3)
        {
            //平面对称
            new_point.plane_symmetry();
        }
        else if (flag == 4)
        {
            //点到点距离
            cout << "请输入另一个点的三维坐标：" << endl;
            cin >> x >> y >> z;
            double distance = new_point.to_point(x, y, z);
            cout << "两点之间的距离为：" << distance << endl;
        }
        else if (flag == 5)
        {
            //点到直线距离
            cout << "请输入直线上的两个点：" << endl;
            cin >> x >> y >> z;
            point *point1 = new point(x, y, z);
            cin >> x >> y >> z;
            point *point2 = new point(x, y, z);
            double distance = new_point.to_line(point1, point2);
            cout << "点到直线的距离为：" << distance << endl;
        }
        else if (flag == 6)
        {
            //点到平面距离
            double A, B, C;
            cout << "请输入平面上的一个点：" << endl;
            cin >> x >> y >> z;
            point *point1 = new point(x, y, z);
            cout << "请输入平面的任一法向量参数：" << endl;
            cin >> A >> B >> C;
            double distance = new_point.to_plane(point1, A, B, C);
            cout << "点到平面的距离为：" << distance << endl;
        }
        else if (flag == 7)
        {
            //退出
            cout << "成功退出！" << endl;
            break;
        }
    }
    return 0;
}
