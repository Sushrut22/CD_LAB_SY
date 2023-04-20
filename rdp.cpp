/*
X → xY
Y → ZwY | xY | ∈
Z → yW
W → zW | ∈
*/


#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long

string s = "x";
int i = 0;
int n = s.size();
bool check(char c) {
    if (i == n) return 0;
    else {
        if (s[i] == c) {
            i++;
            return 1;
        }
        else {
            return 0;
        }
    }
}
bool W() {
    if (check('z')) {
        if (W()) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return true;
    }
}
bool Z() {
    if (check('y')) {
        if (W()) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        return 0;
    }
}

// Y -> ZwY / xY / # 
bool Y() {
    if (Z()) {
        if (check('w')) {
            if (check('y')) {
                return 1;
            }
            else {
                return 0;
            }
        }
        else {
            return 0;
        }
    }
    else if (check('x')) {
        if (Y()) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        return 1;
    }
}

// X -> xY
bool X() {
    if (check('x')) {
        if (Y()) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        return 0;
    }
}
void solve() {
    if (X()) cout << 1;
    else cout << 0;
}

int main()
{
    solve();
    return 0;
}
