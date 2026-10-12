
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int q[100];
    int front = -1, rear = -1;
    int choice, token;

    while (cin >> choice) {
        if (choice == 1) {
            cin >> token;

            if ((rear + 1) % n == front) {
                cout << "Queue Overflow" << endl;
            }
            else {
                if (front == -1)
                    front = 0;

                rear = (rear + 1) % n;
                q[rear] = token;
            }
        }
        else if (choice == 2) {
            if (front == -1) {
                cout << "Queue Underflow" << endl;
            }
            else {
                cout << "Served: " << q[front] << endl;

                if (front == rear) {
                    front = rear = -1;
                }
                else {
                    front = (front + 1) % n;
                }
            }
        }

        if (front == -1)
            cout << "Front: Empty" << endl;
        else
            cout << "Front: " << q[front] << endl;
    }

    return 0;
}
