#include <iostream>
#include <cmath>

using namespace std;

// Функция для вычисления расстояния между двумя точками в 3D
double distance(double x1, double y1, double z1, double x2, double y2, double z2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
}

// Функция для вычисления площади треугольника по длинам сторон (формула Герона)
double triangleArea(double a, double b, double c) {
    double p = (a + b + c) / 2.0; // полупериметр
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main() {
    double x1, y1, z1;
    double x2, y2, z2;
    double x3, y3, z3;
    double x4, y4, z4;

    cout << "Введите координаты вершины A (x y z): ";
    cin >> x1 >> y1 >> z1;

    cout << "Введите координаты вершины B (x y z): ";
    cin >> x2 >> y2 >> z2;

    cout << "Введите координаты вершины C (x y z): ";
    cin >> x3 >> y3 >> z3;

    cout << "Введите координаты вершины D (x y z): ";
    cin >> x4 >> y4 >> z4;

    // Длины ребер пирамиды (основание: ABC)
    double AB = distance(x1, y1, z1, x2, y2, z2);
    double BC = distance(x2, y2, z2, x3, y3, z3);
    double CA = distance(x3, y3, z3, x1, y1, z1);

    // Площади треугольников основания и боковых граней
    double baseArea = triangleArea(AB, BC, CA);

    // Боковые грани: A-D-B, B-D-C, C-D-A
    double AD = distance(x1, y1, z1, x4, y4, z4);
    double BD = distance(x2, y2, z2, x4, y4, z4);
    double CD = distance(x3, y3, z3, x4, y4, z4);

    double side1 = triangleArea(AB, AD, BD);
    double side2 = triangleArea(BC, BD, CD);
    double side3 = triangleArea(CA, CD, AD);

    double totalSurface = baseArea + side1 + side2 + side3;

    cout << "Полная поверхность треугольной пирамиды: " << totalSurface << endl;

    return 0;
}