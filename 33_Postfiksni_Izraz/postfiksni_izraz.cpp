#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

bool isoperator(char c)
{
    return c == '+' || c == '*';
}

void prevedi (string izraz)
{
    stack<char> op;
    for (char c : izraz) {
        if (c == ')') {
            cout << op.top();
            op.pop();
        } else if (isdigit(c)) {
            cout << c;
        } else if (isoperator(c)) {
            op.push(c);
        }
    }
}

int main(void)
{
    string izraz;
    cin >> izraz;

    prevedi(izraz);
    
    return 0;
}
