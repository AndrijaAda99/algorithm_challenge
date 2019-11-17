#include <iostream>
#include <string>

using namespace std;

string pref(const string& post, const string& infx)
{
    if (post == "" && infx == "") {
        return "";
    }

    char koren = post[post.size() - 1];
    cout << koren << endl;
    size_t l = infx.find(koren);
    size_t d = infx.size() - 1 - l;

    string post_l = post.substr(0, l);
    string post_d = post.substr(l, d);
    string infx_l = infx.substr(0, l);
    string infx_d = infx.substr(l + 1, d);

    return koren + pref(post_l, infx_l) + pref(post_d, infx_d);
}

int main(void)
{
    string post;
    string infx;

    cin >> post >> infx;

    cout << pref(post, infx);
    
    return 0;
}
