#include <iostream>

void swapNumbers(double &a, double &b) {
    double temp = a;
    a = b;
    b = temp;
}

int main() {
    double x, y;
    std::cout << "Enter value for x: ";
    std::cin >> x;
    std::cout << "Enter value for y: ";
    std::cin >> y;

    std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;

    swapNumbers(x, y);

    std::cout << "After swap:  x = " << x << ", y = " << y << std::endl;
    return 0;
}


