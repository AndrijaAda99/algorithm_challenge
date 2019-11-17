#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

bool isoperator(char c)
{
    return c == '+' || c == '*';
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
    stack<int> nums;

    for (char c : izraz) {
        if (c == ')') {
            int a = nums.top(); nums.pop();
            int b = nums.top(); nums.pop();
            char op_cur = op.top(); op.pop();
            nums.push(izracunaj(a, b, op_cur));
        } else if (isdigit(c)) {
            nums.push(c - '0');
        } else if (isoperator(c)) {
            op.push(c);
        }
    }

    return nums.top();
}

int main(void)
{
    string izraz;
    cin >> izraz;

    cout << vrednost(izraz) << endl;
    
    return 0;
}
