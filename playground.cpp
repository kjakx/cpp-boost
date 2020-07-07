#include <bits/stdc++.h>
using namespace std;
// rep macro
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rev(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rev2(i, s, n) for (int i = (int)(n) - 1; i >= (int)(s); i--)
#define bitrep(i, n) for (int i = 0; i < (int)(1 << n); i++)
// vector macro
#define all(v) v.begin(), v.end()
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
// math macro
#define lcm(a, b) a / __gcd(a, b) * b
// print macro
#define println(x) cout << x << endl
#define Yes println("Yes")
#define No println("No")
#define YES println("YES")
#define NO println("NO")
// pair macro
#define x first
#define y second
using pii = pair<int, int>;
using pdd = pair<double, double>;

int main()
{
    int n, m; cin >> n >> m;
    vvb friends(n, vb(n, false));
    rep(i, m)
    {
        int a, b; cin >> a >> b; a--; b--;
        friends[a][b] = friends[b][a] = true;
    }
    int max_gs = 0;
    bitrep(b, n)
    {
        bitset<12> bs(b);
        int gs = bs.count();
        rep(i, n-1)
        {
            rep2(j, i+1, n)
            {
                if ((bs[i] == 1 && bs[j] == 1) && friends[i][j] == false)
                {
                    gs = -1;
                    break;
                }
            }
            if (gs < 0) break;
        }
        max_gs = max(gs, max_gs);
    }
    cout << max_gs << endl;
}