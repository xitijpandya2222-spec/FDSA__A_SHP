
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    int n, choice, patient;

    cout << "Enter Number : ";
    cin >> n;

    while (n--) {
        cout << "Enter Choice (1-Arrive, 2-Attend) : ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Patient : ";
            cin >> patient;
            q.push(patient);
        }
        else if (choice == 2) {
            if (q.empty()) {
                cout << "Underflow\n";
            }
            else {
                q.pop();
            }
        }
        else {
            cout << "Invalid Choice\n";
        }

        if (q.empty())
            cout << "Empty\n";
        else
            cout << q.front() << "\n";
    }

    return 0;
}
