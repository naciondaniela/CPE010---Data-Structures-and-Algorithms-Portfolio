#include <iostream>
#include <cmath>
#include <string>

class Triangle {
private:
    double totalAngle, angleA, angleB, angleC;
    double sideA, sideB, sideC;
public:
    Triangle(double A, double B, double C, double sA, double sB, double sC);
    void setAngles(double A, double B, double C);
    const bool validateTriangle();
    double getPerimeter();
    double getArea();
    std::string classifyTriangle();
};

int main() {
    double A, B, C, sA, sB, sC;

    std::cout << "Enter angle A: ";
    std::cin >> A;
    std::cout << "Enter angle B: ";
    std::cin >> B;
    std::cout << "Enter angle C: ";
    std::cin >> C;
    std::cout << "Enter side A (opposite angle A): ";
    std::cin >> sA;
    std::cout << "Enter side B (opposite angle B): ";
    std::cin >> sB;
    std::cout << "Enter side C (opposite angle C): ";
    std::cin >> sC;

    Triangle set1(A, B, C, sA, sB, sC);

    if (set1.validateTriangle()) {
        std::cout << "\nThe shape is a valid triangle.\n";
    } else {
        std::cout << "\nThe shape is NOT a valid triangle.\n";
    }

    std::cout << "Perimeter: " << set1.getPerimeter() << std::endl;
    std::cout << "Area: " << set1.getArea() << std::endl;
    std::cout << "Classification: " << set1.classifyTriangle() << std::endl;

    return 0;
}

Triangle::Triangle(double A, double B, double C, double sA, double sB, double sC) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
    sideA = sA;
    sideB = sB;
    sideC = sC;
}

void Triangle::setAngles(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

const bool Triangle::validateTriangle() {
    return (totalAngle <= 180);
}

double Triangle::getPerimeter() {
    return sideA + sideB + sideC;
}

double Triangle::getArea() {
    double s = getPerimeter() / 2;
    return std::sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
}

std::string Triangle::classifyTriangle() {
    double maxAngle = angleA;
    if (angleB > maxAngle) maxAngle = angleB;
    if (angleC > maxAngle) maxAngle = angleC;

    if (maxAngle < 90) {
        return "Acute-angled";
    } else if (maxAngle > 90) {
        return "Obtuse-angled";
    } else {
        return "Others";
    }
}



