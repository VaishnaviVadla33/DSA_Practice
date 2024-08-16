#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

int splitStringBySpace(const string& str) {
    vector<string> tokens;
    istringstream iss(str);
    string tokenList;
    int stack[100], top = -1;
    
    while (iss >> tokenList) {
        tokens.push_back(tokenList);
    }
    
    for (const string& token : tokens) {// token and tokenList are same here in code
        if (token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
            if (top < 1) {
                throw runtime_error("Invalid postfix expression");
            }
                int a = stack[top--];
                int b = stack[top--];
            int result;
            if (token[0] == '+') {
                result = b + a;
            } else if (token[0] == '-') {
                result = b - a;
            } else if (token[0] == '*') {
                result = b * a;
            } else if (token[0] == '/') {
                if (a == 0) {
                    throw runtime_error("Division by zero");
                }
                result = b / a;
            } else {
                throw runtime_error("Unknown operator");
            }
            stack[++top] = result;
        } else {
            try {
                int i = stoi(token);
                stack[++top] = i;
            } catch (invalid_argument& e) {
                throw runtime_error("Invalid token in expression");
            }
        }
    }

    if (top != 0) {
        throw runtime_error("Invalid postfix expression");
    }

    return stack[top];
}

int main() {
    string s = "9 3 4 * 8 + 4 / -";
    cout << "Postfix expression is: " << s << endl;
    try {
        int v = splitStringBySpace(s);
        cout << "Result of expression: " << v << endl;
    } catch (runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
