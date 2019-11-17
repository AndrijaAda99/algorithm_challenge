#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

bool is_operator(char op)
{
    return op == '+' || op == '*';
}

bool priority(char op1, char op2)
{
    return !(op1 == '+' && op2 == '*');
}

int izracunaj(int a, int b, char op)
{
    if (op == '+') {
        return a + b;
    }

    return a * b;
}

int vrednost(string izraz)
{
    stack<char> op;
    stack<int> s;
    
    for (char c : izraz) {
        if (isdigit(c)) {
            s.push(c - '0');
        }
        if (is_operator(c)) {
            while (!op.empty() && is_operator(op.top()) && 
                   priority(op.top(), c)) {
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                s.push(izracunaj(a, b, op.top()));
                op.pop();
            }
            op.push(c);
        }
        if (c == '(') {
            op.push(c);
        }
        if (c == ')') {
            while (op.top() != '(') {
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                s.push(izracunaj(a, b, op.top()));
                op.pop();
            }
            op.pop();
        }
    }

    while (!op.empty()) {
        int a = s.top(); s.pop();
        int b = s.top(); s.pop();
        s.push(izracunaj(a, b, op.top()));
        op.pop();
    }

    return s.top();
}

int main(void)
{
    string izraz;
    cin >> izraz;

    cout << vrednost(izraz) << endl;
    
    return 0;
}
