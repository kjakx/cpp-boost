#include <bits/stdc++.h>
using namespace std;
// rep macro
#define rep(i, n)        for (int i = 0; i < (int)(n); i++)
#define rev(i, n)        for (int i = (int)(n - 1); i >= 0; i--)
#define rep2(i, s, n)    for (int i = (s); i < (int)(n); i++)
#define rev2(i, s, n)    for (int i = (int)(n) - 1; i >= (int)(s); i--)
#define bitrep(i, n)     for (int i = 0; i < (1 << (int)(n)); i++)
#define bitrep2(i, s, n) for (int i = (s); i < (1 << (int)(n)); i++)
const int di[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dj[8] = {0, 1, 0, -1, -1, 1, 1, -1};
// type macro
using ll = int64_t;
// vector macro
#define all(v) v.begin(), v.end()
using  vi = vector<int>;
using vvi = vector<vector<int>>;
using  vu = vector<size_t>;
using vvu = vector<vector<size_t>>;
using  vl = vector<ll>;
using vvl = vector<vector<ll>>;
using  vd = vector<double>;
using vvd = vector<vector<double>>;
using  vb = vector<bool>;
using vvb = vector<vector<bool>>;
using  vc = vector<char>;
using vvc = vector<vector<char>>;
using  vs = vector<string>;
using vvs = vector<vector<string>>;
// pair macro
#define fi first
#define sj second
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
// math macro
#define lcm(a, b) a / __gcd(a, b) * b
#define dist(a, b) sqrt(pow(a.fi - b.fi, 2) + pow(a.sj - b.sj, 2))
// print macro
#define println(x) cout << x << endl
#define Yes println("Yes")
#define No println("No")
#define YES println("YES")
#define NO println("NO")
// memo
// desc sort: sort(vec.begin(), vec.end(), greater<int>());

bool on_grid(int i, int j, int r, int c)
{
    return (i >= 0 && i < r && j >= 0 && j < c);
}

int main()
{
    int h, w, n; cin >> h >> w >> n;
    vvc g(h, vc(w));
    pii s;
    vector<pii> e(n);
    rep(i, h)
        rep(j, w)
        {
            cin >> g[i][j];
            if (g[i][j] == 'S') s = pii(i, j);
            if (isdigit(g[i][j])) e[g[i][j] - '0' - 1] = pii(i, j);
        }
    
    int t = 0;
    rep(i, n)
    {
        vvb seen(h, vb(w, false));
        seen[s.fi][s.sj] = true;
        queue<pii> q;
        q.push(s);
        while (!q.empty())
        {
            queue<pii> qt;
            while (!q.empty())
            {
                qt.push(q.front()); q.pop();
            }
            while (!qt.empty())
            {
                pii now = qt.front(); qt.pop();
                rep(i, 4)
                    if (on_grid(now.fi+di[i], now.sj+dj[i], h, w) 
                        && seen[now.fi+di[i]][now.sj+dj[i]] == false 
                        && g[now.fi+di[i]][now.sj+dj[i]] != 'X')
                    {
                        seen[now.fi+di[i]][now.sj+dj[i]] = true;
                        q.push(pii(now.fi+di[i], now.sj+dj[i]));
                    }
            }
            t++;
            if (seen[e[i].fi][e[i].sj] == true) break;
        }
        s = e[i];
    }
    cout << t << endl;
}