#include<bits/stdc++.h>
using namespace std;
#define nl '\n'
#define int long long

signed main()
{
    string s;
    cin >> s;
    char fir = s[0];
    s = s.substr(2, s.size());
    cout << s << nl;
    map<char, int> mpp;
    if (s.back() > 'z' || s.back() < 'a')
    {
        cout << "Invalid" << nl;
        return 0;
    }
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] >= 'a' && s[i] <= 'z') mpp[s[i]]++;
    }


    for (auto& pp : mpp)
    {
        cout << pp.first << " " << pp.second << nl;
    }
    cout << nl;




    for (auto it : mpp)
    {
        if (it.second >= 2) {
            cout << "Invalid" << nl;
            return 0;
        }
    }
    for (int i = 1; i < s.size(); i++) {
        if (s[i] <= 'z' && s[i] >= 'a') {
            if (s[i - 1] <= 'z' && s[i - 1] >= 'a') {
                cout << "Invalid" << nl;
                return 0;
            }
        }
        if (s[i] > 'z' || s[i] < 'a') {
            if (s[i - 1] > 'z' || s[i - 1] < 'a') {
                cout << "Invalid" << nl;
                return 0;
            }
        }
    }
    int op = 4;
    int cc = 0;
    while (s.size() > 1) {
        if (op == 4) {
            string temp;
            for (int i = 0; i < s.size(); ++i)
            {
                if (s[i] == '/') {
                    int a = -1, b = -1;
                    a = s[i - 1] - '0';
                    if (s[i - 1] < '0' || s[i - 1] > '4') {
                        cout << "MOV R" << cc << ", " << s[i - 1] << nl;
                        a = cc;
                        cc++;
                    }
                    if (s[i + 1] < '0' || s[i + 1] > '4') {
                        b = cc;
                        cout << "MOV R" << cc << ", " << s[i + 1] << nl;
                        cc++;
                    }
                    else b = s[i + 1] - '0';
                    temp = s.substr(0, i - 1);
                    temp.push_back(a + '0');
                    temp += s.substr(i + 2, s.size());
                    cout << "DIV R" << a << ", R" << b << nl;
                    s = temp;
                    break;
                }
            }
            if (temp.size() == 0)
            {
                op = 3;
            }
        }
        else if (op == 3) {
            string temp;
            for (int i = 0; i < s.size(); ++i)
            {
                if (s[i] == '*') {
                    int a = -1, b = -1;
                    a = s[i - 1] - '0';
                    if (s[i - 1] < '0' || s[i - 1] > '4') {
                        cout << "MOV R" << cc << ", " << s[i - 1] << nl;
                        a = cc;
                        cc++;
                    }
                    if (s[i + 1] < '0' || s[i + 1] > '4') {
                        b = cc;
                        cout << "MOV R" << cc << ", " << s[i + 1] << nl;
                        cc++;
                    }
                    else b = s[i + 1] - '0';
                    temp = s.substr(0, i - 1);
                    temp.push_back(a + '0');
                    temp += s.substr(i + 2, s.size());
                    cout << "MUL R" << a << ", R" << b << nl;
                    s = temp;
                    break;
                }
            }
            if (temp.size() == 0)
                op = 2;
        }
        else if (op == 2) {
            string temp;

            for (int i = 0; i < s.size(); ++i)
            {
                if (s[i] == '+') {
                    int a = -1, b = -1;
                    a = s[i - 1] - '0';
                    if (s[i - 1] < '0' || s[i - 1] > '4') {
                        cout << "MOV R" << cc << ", " << s[i - 1] << nl;
                        a = cc;
                        cc++;
                    }
                    if (s[i + 1] < '0' || s[i + 1] > '4') {
                        b = cc;
                        cout << "MOV R" << cc << ", " << s[i + 1] << nl;
                        cc++;
                    }
                    else b = s[i + 1] - '0';
                    temp = s.substr(0, i - 1);
                    temp.push_back(a + '0');
                    temp += s.substr(i + 2, s.size());
                    cout << "ADD R" << a << ", R" << b << nl;
                    s = temp;
                    break;
                }
            }
            if (temp.size() == 0)
                op = 1;
        }
        else if (op == 1) {
            string temp;
            for (int i = 0; i < s.size(); ++i)
            {
                if (s[i] == '-') {
                    int a = -1, b = -1;
                    a = s[i - 1] - '0';
                    if (s[i - 1] < '0' || s[i - 1] > '4') {
                        cout << "MOV R" << cc << ", " << s[i - 1] << nl;
                        a = cc;
                        cc++;
                    }
                    if (s[i + 1] < '0' || s[i + 1] > '4') {
                        b = cc;
                        cout << "MOV R" << cc << ", " << s[i + 1] << nl;
                        cc++;
                    }
                    else b = s[i + 1] - '0';
                    temp = s.substr(0, i - 1);
                    temp.push_back(a + '0');
                    temp += s.substr(i + 2, s.size());
                    cout << "SUB R" << a << ", R" << b << nl;
                    s = temp;
                    break;
                }
            }
            if (temp.size() == 0)
                op = 0;
        }
        else {
            break;
        }
    }
    cout << "MOV " << fir << ", R" << s[0] << nl;
    return 0;
}

