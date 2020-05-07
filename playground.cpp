#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define println(x) cout << x << endl
#define fi first
#define se second
#define Yes println("Yes")
#define No println("No")
#define YES println("YES")
#define NO println("NO")
using pii = pair<int, int>;

int main()
{
    string s, t;
    cin >> s >> t;
    bool restorable = false;
    int cnt = s.size() - t.size();
    while (cnt >= 0)
    {
        string st = s;
        for (int i = t.size() - 1; i >= 0; i--)
        {
            if (t[i] == st[i+cnt])
            {
                if (i == 0)
                {
                    restorable = true;
                }
            }
            else if (st[i+cnt] == '?')
            {
                st[i+cnt] = t[i];
                if (i == 0)
                {
                    restorable = true;
                }
            }
            else break;
        }
        if (restorable)
        {
            s = st;
            break;
        }
        cnt--;
    }
    if (restorable) 
    {
        rep(i, s.size())
        {
            if (s[i] == '?') s[i] = 'a';
        }
        println(s);
    }
    else println("UNRESTORABLE");
}