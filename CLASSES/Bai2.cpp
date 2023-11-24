#include <iostream>
#include <cmath>
using namespace std;

int evaluateExpression(string expression) {
    int result = 0;
    int sign = 1; // D?u c?a s? hi?n t?i (1 là duong, -1 là âm)

    for (int i = 0; i < expression.size(); ++i) {
        char c = expression[i];

        if (c == '+') {
            sign = 1;
        } else if (c == '-') {
            sign = -1;
        } else if (c == '*') {
            // X? lý phép nhân
            int operand = 0;
            ++i; // B? qua ký t? '*'
            while (i < expression.size() && isdigit(expression[i])) {
                operand = operand * 10 + (expression[i] - '0');
                ++i;
            }
            --i; // Ði?u ch?nh ch? s? c?a vòng l?p

            result += sign * operand;
        } else if (c == 'a') {
            int operand = 0;
            i += 3; 
            while (i < expression.size() && isdigit(expression[i])) {
                operand = operand * 10 + (expression[i] - '0');
                ++i;
            }
            --i;

            result += sign * abs(operand);
        } else if (isdigit(c)) {
            int operand = c - '0';
            while (i + 1 < expression.size() && isdigit(expression[i + 1])) {
                operand = operand * 10 + (expression[i + 1] - '0');
                ++i;
            }

            result += sign * operand;
        }
    }

    return result;
}

int main() {
    string expression;
    getline(cin, expression);

    int result = evaluateExpression(expression);
    cout << result << endl;

    return 0;
}

