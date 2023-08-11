#include <iostream>
#include <string>
#include <cctype>
#include <windows.h>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

float calculator(float n1, float n2, char op) {
    switch (op) {
    case '-':
        return n1 - n2;
    case '+':
        return n1 + n2;
    case '/':
        return n1 / n2;
    case '*':
        return n1 * n2;
    case '%':
        int num1 = static_cast<int>(n1);
        int num2 = static_cast<int>(n2);
        return num1 % num2;
    }
    return 0.0f;
}

bool isValidInput(const std::string& input) {
    bool valid = false;
    bool hasDot = false;  

    for (char c : input) {
        if (isdigit(c)) {
            valid = true;
        }
        else if (c == '.' && !hasDot) {
            hasDot = true;
            valid = true;
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%') {
            valid = true;
        }
        else {
            valid = false;
            break;
        }
    }

    return valid;
}

int main() {
    float f_num1, f_num2;
    char c_op;

    SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_BLUE);

    std::cout << "==============================================" << std::endl;
    std::cout << "            Arithmetic Calculator             " << std::endl;
    std::cout << "             By Sara Ahmad Malik              " << std::endl;
    std::cout << "==============================================" << std::endl;


    while (true) {
        SetConsoleTextAttribute(hConsole, 7);
        std::cout << "Enter first Number: ";
        std::string num1Input;
        std::getline(std::cin, num1Input);

        if (num1Input == "exit" || num1Input == "quit") {
            SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED);
            std::cout << "Calculator closed." << std::endl;
            break;
        }

        while (!isValidInput(num1Input)) {
            SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED);
            std::cout << "Expected a number (integer or floating-point): ";
            std::getline(std::cin, num1Input);
        }

        f_num1 = std::stof(num1Input);

        std::cout << "Enter second Number: ";
        SetConsoleTextAttribute(hConsole, 7);
        std::string num2Input;
        std::getline(std::cin, num2Input);

        if (num2Input == "exit" || num2Input == "quit") {
            SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED);
            std::cout << "Exited." << std::endl;
            break;
        }

        while (!isValidInput(num2Input)) {
            SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED);
            std::cout << "Expected a number (integer or floating-point): ";
            std::getline(std::cin, num2Input);
 
        }

        f_num2 = std::stof(num2Input);

        SetConsoleTextAttribute(hConsole, 7);
        std::cout << "Enter arithmetic operation that you want to perform: (+, -, %, /, *) ";  
        std::string operatorInput;
        std::getline(std::cin, operatorInput);


        if (operatorInput == "exit" || operatorInput == "quit") {
            SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
            std::cout << "Calculator closed." << std::endl;
            break;
        }

        while (!isValidInput(operatorInput) || operatorInput.size() != 1) {
            SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED);
            std::cout << "Expected a single character (+, -, *, /, %): ";
            SetConsoleTextAttribute(hConsole, 7);
            std::getline(std::cin, operatorInput);
        }

        c_op = operatorInput[0];

        float result = calculator(f_num1, f_num2, c_op);

        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
        std::cout << "Result: " << result << std::endl;

        std::cout << std::endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
        std::cout << "For quitting the calculator, type 'exit' or 'quit'" << std::endl << std::endl;
    }

    return 0;
}
