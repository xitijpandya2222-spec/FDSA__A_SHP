#include <iostream>
using namespace std;

struct S {
    string name;
    S *next;
};

struct D {
    string name;
    D *next, *prev;
};

S *sh = NULL;
D *dh = NULL;

void join(string x) {
    S *a = new S{x, NULL};
    D *b = new D{x, NULL, NULL};

    if (!sh) {
        sh = a; a->next = sh;
        dh = b; b->next = b->prev = b;
        return;
    }

    S *p = sh;
    while (p->next != sh) p = p->next;
    p->next = a; a->next = sh;

    D *q = dh->prev;
    q->next = b; b->prev = q;
    b->next = dh; dh->prev = b;
}

void leave(string x) {
    if (!sh) return;

    S *p = sh, *prev = NULL;
    do {
        if (p->name == x) break;
        prev = p; p = p->next;
    } while (p != sh);

    if (p->name != x) {
        cout << "Student not found\n";
        return;
    }

    if (p == sh) {
        S *last = sh;
        while (last->next != sh) last = last->next;
        sh = sh->next;
        last->next = sh;
    } else
        prev->next = p->next;

    D *q = dh;
    do {
        if (q->name == x) break;
        q = q->next;
    } while (q != dh);

    q->prev->next = q->next;
    q->next->prev = q->prev;

    if (q == dh) dh = q->next;

    delete p;
    delete q;
}

void display() {
    if (!sh) {
        cout << "Circle is empty\n";
        return;
    }

    S *p = sh;
    cout << "Singly: ";
    do {
        cout << p->name << " ";
        p = p->next;
    } while (p != sh);

    D *q = dh;
    cout << "\nDoubly: ";
    do {
        cout << q->name << " ";
        q = q->next;
    } while (q != dh);

    cout << endl;
}

int main() {
    int ch;
    string name;

    do {
        cout << "\n1.Join  2.Leave  3.Display  4.Exit\nChoice: ";
        cin >> ch;

        if (ch == 1) {
            cout << "Enter student: ";
            cin >> name;
            join(name);
            display();
        }
        else if (ch == 2) {
            cout << "Enter student: ";
            cin >> name;
            leave(name);
            display();
        }
        else if (ch == 3)
            display();

    } while (ch != 4);

    return 0;
}