#include <iostream>
#include <limits>
using namespace std;

// Implementing two stacks using one array
class TwoStacks {
public:
    int stack[100], n = 100, top1 = n / 2 + 1, top2 = n / 2;

    void push1(int val) {
        if (top1 <= 0) {
            cout << "Stack Overflow" << endl;
        } else {
            top1--;
            stack[top1] = val;
            cout << val << " pushed to stack1" << endl;
        }
    }

    void push2(int val) {
        if (top2 >= n - 1) {
            cout << "Stack Overflow" << endl;
        } else {
            top2++;
            stack[top2] = val;
            cout << val << " pushed to stack2" << endl;
        }
    }

    void pop1() {
        if (top1 >= n / 2 + 1) {
            cout << "Stack Underflow" << endl;
        } else {
            cout << "The popped element from stack1 is " << stack[top1] << endl;
            top1++;
        }
    }

    void pop2() {
        if (top2 <= n / 2) {
            cout << "Stack Underflow" << endl;
        } else {
            cout << "The popped element from stack2 is " << stack[top2] << endl;
            top2--;
        }
    }

    void display() {
        cout << "Stack1 elements: ";
        if (top1 <= n / 2) {
            for (int i = top1; i <= n / 2; i++) {
                cout << stack[i] << " ";
            }
        } else {
            cout << "Empty";
        }
        cout << endl;

        cout << "Stack2 elements: ";
        if (top2 >= n / 2 + 1) {
            for (int i = top2; i >= n / 2 + 1; i--) {
                cout << stack[i] << " ";
            }
        } else {
            cout << "Empty";
        }
        cout << endl;
    }
};

int main() {
    TwoStacks ss;
    int ch, val;
    cout << "1) Push in stack1" << endl;
    cout << "2) Push in stack2" << endl;
    cout << "3) Pop from stack1" << endl;
    cout << "4) Pop from stack2" << endl;
    cout << "5) Display stack" << endl;
    cout << "6) Exit" << endl;

    do {
        cout << "Enter choice: ";
        while (!(cin >> ch)) { // Validate integer input for choice
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid choice. Please enter a number: ";
        }

        switch (ch) {
            case 1: {
                cout << "Enter value to be pushed in stack1: ";
                while (!(cin >> val)) { // Validate integer input for value
                    cin.clear(); // Clear error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                    cout << "Invalid value. Please enter a number: ";
                }
                ss.push1(val);
                break;
            }
            case 2: {
                cout << "Enter value to be pushed in stack2: ";
                while (!(cin >> val)) { // Validate integer input for value
                    cin.clear(); // Clear error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                    cout << "Invalid value. Please enter a number: ";
                }
                ss.push2(val);
                break;
            }
            case 3: {
                ss.pop1();
                break;
            }
            case 4: {
                ss.pop2();
                break;
            }
            case 5: {
                ss.display();
                break;
            }
            case 6: {
                cout << "Exiting..." << endl;
                break;
            }
            default: {
                cout << "Invalid Choice. Please enter a number between 1 and 6." << endl;
            }
        }
    } while (ch != 6);

    return 0;
}
