#include <iostream>
using namespace std;

#define MAX 5

int st[MAX], top = -1;

void push(int x) {
    if (top == MAX - 1)
        cout << "Stack is full\n";
    else
        st[++top] = x;
}

void pop() {
    if (top == -1)
        cout << "Stack is empty\n";
    else
        cout << "Removed: " << st[top--] << endl;
}

void display() {
    if (top == -1) {
        cout << "Stack is empty\n";
        return;
    }

    cout << "Stack: ";
    for (int i = top; i >= 0; i--)
        cout << st[i] << " ";
    cout << endl;
}

int main() {
    int ch, x;

    do {
        cout << "\n1.Push  2.Pop  3.Display  4.Exit";
        cout << "\nEnter choice: ";
        cin >> ch;

        if (ch == 1) {
            cout << "Enter tray number: ";
            cin >> x;
            push(x);
        }
        else if (ch == 2)
            pop();
        else if (ch == 3)
            display();

    } while (ch != 4);

    return 0;
}