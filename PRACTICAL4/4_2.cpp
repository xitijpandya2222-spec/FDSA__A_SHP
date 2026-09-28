#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head = NULL;

void insertFront(int x) {
    Node *n = new Node{x, head};
    head = n;
}

void insertEnd(int x) {
    Node *n = new Node{x, NULL};

    if (!head) {
        head = n;
        return;
    }

    Node *p = head;
    while (p->next)
        p = p->next;

    p->next = n;
}

void insertPos(int x, int pos) {
    if (pos == 1) {
        insertFront(x);
        return;
    }

    Node *p = head;

    for (int i = 1; i < pos - 1 && p; i++)
        p = p->next;

    if (!p) {
        cout << "Invalid position\n";
        return;
    }

    Node *n = new Node{x, p->next};
    p->next = n;
}

void display() {
    Node *p = head;

    cout << "Queue: ";
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    int ch, x, pos;

    do {
        cout << "\n1. Add Front";
        cout << "\n2. Add End";
        cout << "\n3. Insert at Position";
        cout << "\n4. Display";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> ch;

        if (ch == 1) {
            cout << "Enter patient token: ";
            cin >> x;
            insertFront(x);
            display();
        }
        else if (ch == 2) {
            cout << "Enter patient token: ";
            cin >> x;
            insertEnd(x);
            display();
        }
        else if (ch == 3) {
            cout << "Enter patient token: ";
            cin >> x;
            cout << "Enter position: ";
            cin >> pos;
            insertPos(x, pos);
            display();
        }
        else if (ch == 4)
            display();

    } while (ch != 5);

    return 0;
}