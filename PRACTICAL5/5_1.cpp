#include <iostream>
using namespace std;

struct Node {
    string song;
    Node *prev, *next;
};

Node *head = NULL;

void addBegin(string s) {
    Node *n = new Node{s, NULL, head};
    if (head) head->prev = n;
    head = n;
}

void addEnd(string s) {
    Node *n = new Node{s, NULL, NULL};
    if (!head) {
        head = n;
        return;
    }

    Node *p = head;
    while (p->next) p = p->next;
    p->next = n;
    n->prev = p;
}

void insertAfter(string key, string s) {
    Node *p = head;

    while (p && p->song != key)
        p = p->next;

    if (!p) {
        cout << "Song not found\n";
        return;
    }

    Node *n = new Node{s, p, p->next};

    if (p->next)
        p->next->prev = n;

    p->next = n;
}

void removeSong(string s) {
    Node *p = head;

    while (p && p->song != s)
        p = p->next;

    if (!p) {
        cout << "Song not found\n";
        return;
    }

    if (p->prev)
        p->prev->next = p->next;
    else
        head = p->next;

    if (p->next)
        p->next->prev = p->prev;

    delete p;
}

void display() {
    Node *p = head;
    int count = 0;

    cout << "\nPlaylist: ";
    while (p) {
        cout << p->song << " ";
        count++;
        p = p->next;
    }

    cout << "\nTotal Songs = " << count << endl;
}

int main() {
    int ch;
    string song, key;

    do {
        cout << "\n1. Add Beginning";
        cout << "\n2. Add End";
        cout << "\n3. Insert After Song";
        cout << "\n4. Remove Song";
        cout << "\n5. Display";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "Enter song: ";
            cin >> song;
            addBegin(song);
            display();
            break;

        case 2:
            cout << "Enter song: ";
            cin >> song;
            addEnd(song);
            display();
            break;

        case 3:
            cout << "Enter existing song: ";
            cin >> key;
            cout << "Enter new song: ";
            cin >> song;
            insertAfter(key, song);
            display();
            break;

        case 4:
            cout << "Enter song to remove: ";
            cin >> song;
            removeSong(song);
            display();
            break;

        case 5:
            display();
            break;
        }
    } while (ch != 6);

    return 0;
}