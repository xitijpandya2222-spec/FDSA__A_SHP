#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int priority(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

string postfix(string s) {
    stack<char> st;
    string p = "";

    for (char x : s) {
        if (isdigit(x))
            p += x;

        else if (x == '(')
            st.push(x);

        else if (x == ')') {
            while (st.top() != '(') {
                p += st.top();
                st.pop();
            }
            st.pop();
        }

        else {
            while (!st.empty() && priority(st.top()) >= priority(x)) {
                p += st.top();
                st.pop();
            }
            st.push(x);
        }
    }

    while (!st.empty()) {
        p += st.top();
        st.pop();
    }

    return p;
}

int evaluate(string p) {
    stack<int> st;

    for (char x : p) {
        if (isdigit(x))
            st.push(x - '0');
        else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            if (x == '+') st.push(a + b);
            if (x == '-') st.push(a - b);
            if (x == '*') st.push(a * b);
            if (x == '/') st.push(a / b);
        }
    }

    return st.top();
}

int main() {
    string exp;

    cout << "Enter infix expression: ";
    cin >> exp;

    string p = postfix(exp);

    cout << "Postfix: " << p << endl;
    cout << "Result: " << evaluate(p) << endl;

    return 0;
}