#include <iostream>

void displaySum(double a, double b);
bool isGreater(double a, double b);
bool logicalOperations(bool a, bool b);

int main() {
    double num1, num2;

    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;
    displaySum(num1, num2);

    double a, b;
    std::cout << "\nEnter value for A: ";
    std::cin >> a;
    std::cout << "Enter value for B: ";
    std::cin >> b;
    std::cout << "Is A greater than B? " << (isGreater(a, b) ? "Yes" : "No") << std::endl;

    int inputA, inputB;
    std::cout << "\nEnter value for boolean A (1 = true, 0 = false): ";
    std::cin >> inputA;
    std::cout << "Enter value for boolean B (1 = true, 0 = false): ";
    std::cin >> inputB;
    bool success = logicalOperations(inputA != 0, inputB != 0);
    std::cout << "logicalOperations() returned: " << (success ? "true" : "false") << std::endl;

    return 0;
}

void displaySum(double a, double b) {
    std::cout << "Sum of " << a << " and " << b << " is " << (a + b) << std::endl;
}

bool isGreater(double a, double b) {
    return a > b;
}

bool logicalOperations(bool a, bool b) {
    std::cout << "A AND B = " << (a && b) << std::endl;
    std::cout << "A OR B  = " << (a || b) << std::endl;
    std::cout << "NOT A   = " << (!a) << std::endl;
    std::cout << "NOT B   = " << (!b) << std::endl;
    return true;
}



