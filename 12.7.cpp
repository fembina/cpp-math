#include <iostream>
#include <cmath>
using namespace std;

class Point {
public:
    double x, y;

    void vvod();
    void vyvod() const;

    void moveX(double dx); // перемещение по оси X
    void moveY(double dy); // перемещение по оси Y

    double distanceToOrigin() const; // расстояние до начала координат
    double distanceToPoint(const Point& p) const; // расстояние до другой точки
};

void Point::vvod() {
    cout << "Введите координаты точки (x y): ";
    cin >> x >> y;
}

void Point::vyvod() const {
    cout << "Точка (" << x << ", " << y << ")";
}

void Point::moveX(double dx) {
    x += dx;
}

void Point::moveY(double dy) {
    y += dy;
}

double Point::distanceToOrigin() const {
    return sqrt(x * x + y * y);
}

double Point::distanceToPoint(const Point& p) const {
    double dx = x - p.x;
    double dy = y - p.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    Point p1, p2;

    cout << "Ввод первой точки:\n";
    p1.vvod();

    cout << "Ввод второй точки:\n";
    p2.vvod();

    p1.vyvod();
    cout << "\nРасстояние первой точки до начала координат: " << p1.distanceToOrigin() << endl;

    p2.vyvod();
    cout << "\nРасстояние между двумя точками: " << p1.distanceToPoint(p2) << endl;

    double dx, dy;

    cout << "Введите смещение по X для первой точки: ";
    cin >> dx;
    p1.moveX(dx);
    
    cout << "Введите смещение по Y для первой точки: ";
    cin >> dy;
    p1.moveY(dy);

    cout << "После смещения первая точка: ";
    p1.vyvod();
    cout << endl;

    return 0;
}