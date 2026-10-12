#include <iostream>
using namespace std;

struct Node {
    string page;
    Node *next;
};

Node *top = NULL;

void visit(string p) {
    Node *n = new Node{p, top};
    top = n;
}

void back() {
    if (!top) {
        cout << "No history available\n";
        return;
    }

    cout << "Back from: " << top->page << endl;
    Node *p = top;
    top = top->next;
    delete p;
}

void display() {
    Node *p = top;

    if (!p) {
        cout << "No history\n";
        return;
    }

    cout << "History: ";
    while (p) {
        cout << p->page << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    int ch;
    string page;

    do {
        cout << "\n1.Visit Page  2.Back  3.Display  4.Exit";
        cout << "\nEnter choice: ";
        cin >> ch;

        if (ch == 1) {
            cout << "Enter page: ";
            cin >> page;
            visit(page);
        }
        else if (ch == 2)
            back();
        else if (ch == 3)
            display();

    } while (ch != 4);

    return 0;
}