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

void prevedi(string izraz)
{
    stack<char> op;
    
    for (char c : izraz) {
        if (isdigit(c)) {
            cout << c;
        }
        if (is_operator(c)) {
            while (!op.empty() && is_operator(op.top()) && 
                   priority(op.top(), c)) {
                cout << op.top();
                op.pop();
            }
            op.push(c);
        }
        if (c == '(') {
            op.push(c);
        }
        if (c == ')') {
            while (op.top() != '(') {
                cout << op.top();
                op.pop();
            }
            op.pop();
        }
    }

    while (!op.empty()) {
        cout << op.top();
        op.pop();
    }
}

int main(void)
{
    string izraz;
    cin >> izraz;

    prevedi(izraz);
    
    return 0;
}
