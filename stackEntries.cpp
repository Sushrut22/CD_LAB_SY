#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nl "\n"


signed main()
{
    map <pair<int, char>, pair<char, int>> mp;
    mp[{0, '('}] = { 's',3 };
   


 // mp[{6, 'a'}] = { 'r',2 };
 // mp[{6, 'b'}] = { 'r',2 };
 // mp[{6, '$'}] = { 'r',2 };

    map <pair<int, char>, int> gp;
    gp[{0, 'S'}] = 2;
    gp[{3, 'S'}] = 4;

    map <int, pair<int, char>> rp;
    rp[0] = { 6,'S' }, rp[2] = { 2,'S' };

    function <void(string)> check = [&](string ip) {
        string st; st.push_back('0');
        int ptr = 0; bool temp = 0;
        int n = ip.length();
        int ct = 0;
        cout << "stack          top_of_stack  I/P    Operation" << endl;
        while (ptr < n)
        {
            cout << st << " ";

            for (int i = 0;i < 15 - st.size(); ++i)
            {
                cout << " ";
            }

            auto t = st.back() - '0';
            if (!mp.count({ t,ip[ptr] })) break;
            if (t == 2 && ip[ptr] == '$')
            {
                cout << 2 << "            $        Accepted" << endl;
                temp = 1; 
                break;
            }
            if (mp[{t, ip[ptr]}].first == 's')
            {
                cout << t << "            " << ip[ptr] << "        ";
                cout << "shift" << " " << endl;
                st.push_back(ip[ptr]);
                st.push_back(mp[{t, ip[ptr]}].second + '0');
                ptr++;
                // p(st)
                continue;
            }
            else
            {
                cout << t << "            " << ip[ptr] << "        ";
                cout << "reduce" << " " << endl;
                int pops = rp[mp[{t, ip[ptr]}].second].first;
                char g = rp[mp[{t, ip[ptr]}].second].second;
                while (pops--) { if (st.empty()) break; st.pop_back(); }
                if (st.empty()) break;
                auto y = st.back() - '0';
                st.push_back(g);
                st.push_back(gp[{ y, g}] + '0');


            }
            
            ct++;
            if (ct > 15) break;
        }
        if (!temp) cout << "\nRejected" << endl;
    };

    string s;
    cin >> s;
    check(s);
    return 0;
}