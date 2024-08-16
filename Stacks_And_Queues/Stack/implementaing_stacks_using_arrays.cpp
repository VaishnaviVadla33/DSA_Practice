#include <iostream>
#include <limits> // Include this header for std::numeric_limits
using namespace std;

int stack[100], n = 100, top = -1; // Define stack array, its size, and initialize top

void push(int val) {
    if (top >= n - 1)
        cout << "Stack Overflow" << endl;
    else {
        top++;
        stack[top] = val;
        cout << val << " pushed to stack." << endl;
    }
}

void pop() {
    if (top <= -1)
        cout << "Stack Underflow" << endl;
    else {
        cout << "The popped element is " << stack[top] << endl;
        top--;
    }
}

void display() {
    if (top >= 0) {
        cout << "Stack elements are: ";
        for (int i = top; i >= 0; i--)
            cout << stack[i] << " ";
        cout << endl;
    } else
        cout << "Stack is empty" << endl;
}

void peek(){
    if(top<=-1){
        cout<<"Stack is empty"<<endl;
    }
    else{
        int val = stack[top];
        cout<<"peek item is:"<<val;
    }
}

int main() {
    int ch, val;
    cout << "1) Push in stack" << endl;
    cout << "2) Pop from stack" << endl;
    cout << "3) Display stack" << endl;
    cout << "4) Peek stack" << endl;
    cout << "5) Exit"<<endl;

    do {
        cout << "Enter choice: ";
        while (!(cin >> ch)) { // Validate integer input for choice
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid choice. Please enter a number: ";
        }

        switch (ch) {
            case 1: {
                cout << "Enter value to be pushed: ";
                while (!(cin >> val)) { // Validate integer input for value
                    cin.clear(); // Clear error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                    cout << "Invalid value. Please enter a number: ";
                }
                push(val);
                break;
            }
            case 2: {
                pop();
                break;
            }
            case 3: {
                display();
                break;
            }
            case 4:{
                peek();
                break;
            }
            case 5: {
                cout << "Exiting..." << endl;
                break;
            }
            default: {
                cout << "Invalid Choice. Please enter a number between 1 and 4." << endl;
            }
        }
    } while (ch != 5);

    return 0;
}
