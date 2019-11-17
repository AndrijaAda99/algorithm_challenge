#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

bool isoperator(char op) 
{
    return op == '+' || op == '*';
} 

int value(int a, int b, char op)
{
    if (op == '+') {
        return a + b;
    }
    return a * b;
}

int vrednost(string izraz)
{
    stack<int> s; 
    for (char c : izraz) {
        if (isdigit(c)) {
            s.push(c - '0');
        } else if (isoperator(c)) {
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();
            s.push(value(a, b, c));
        }
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
