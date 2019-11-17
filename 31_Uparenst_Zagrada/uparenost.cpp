#include <iostream>
#include <stack>

using namespace std;

bool otvorena(char c)
{
    return c == '(' || c == '[' || c == '{';
}

bool zatvorene(char c)
{
    return c == ')' || c == ']' || c == '}';
}

bool uparena(char c1, char c2)
{
    return  (c1 == '(' && c2 == ')') ||
            (c1 == '[' && c2 == ']') ||
            (c1 == '{' && c2 == '}');
}

bool uparenost(string izraz)
{
    stack<char> s;

    for(char c : izraz) {
        if (otvorena(c)) {
            s.push(c);
        } else if (zatvorene(c) && !s.empty() && uparena(s.top(), c)) {
            s.pop();
        } else {
            return false;
        }
    }

    return s.empty();
}

int main(void)
{
    stack<char> s;

    string izraz;
    cin >> izraz;

    if (uparenost(izraz)) {
        cout << "uparene su" << endl;
    } else {
        cout << "nisu uparene" << endl;
    }

    bool a = 5;
    cout << a << endl;
    a = 0;
    cout << a << endl;
    cout << sizeof (bool) << endl;
    
    return 0;
}
