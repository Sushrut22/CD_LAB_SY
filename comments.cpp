#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long

signed main()
{
    string st, s;
    while (getline(cin, st))
    {
        s += st;
    }
    int sz = s.length();
    if (s[0] == '/' && s[1] == '/')
    {
        cout << "It's a comment!" << nl;
        return 0;
    }
    if (s[0] == '/' and s[1] == '*' and s[sz - 2] == '*' and s[sz - 1] == '/' and sz > 4)
    {
        cout << "It's a comment!" << nl;
        return 0;
    }
    cout << "It's not a comment!" << nl;
    return 0;
}