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
#include <cmath>
const int dio[6] = {  1,  0, -1,  0, -1,  1};
const int djo[6] = {  0,  1,  0, -1,  1,  1};
const int die[6] = {  1,  0, -1,  0, -1,  1};
const int dje[6] = {  0,  1,  0, -1, -1, -1};

bool on_grid(int i, int j, int r, int c)
{
    return (i >= 0 && i < r && j >= 0 && j < c);
}

int main()
{
    int w, h; cin >> w >> h;
    vvi g(h, vi(w));
    rep(i, h)
        rep(j, w)
            cin >> g[i][j];
    
    vvb seen(h, vb(w, false));
    rep(i, h)rep(j, w)
    {
        if (g[i][j] == 0 && seen[i][j] == false)
        {
            bool flag = true;
            queue<pii> q;
            q.push(pii(i, j));
            vvb seent(h, vb(w, false));
            while (!q.empty())
            {
                pii now = q.front(); q.pop();
                seen[now.fi][now.sj] = true;
                seent[now.fi][now.sj] = true;
                if (now.fi % 2 == 0)
                {
                    rep(k, 6)
                    {   
                        if (on_grid(i+dio[k], j+djo[k], h, w))
                        {
                            if (g[i+dio[k]][j+djo[k]] == 0 && seen[i+dio[k]][j+djo[k]] == false)
                                q.push(pii(i+dio[k], j+djo[k]));
                        }
                        else
                        {
                            flag = false;
                        }
                    }
                }
                else
                {
                    rep(k, 6)
                    {
                        if (on_grid(i+die[k], j+dje[k], h, w))
                        {
                            if (g[i+die[k]][j+dje[k]] == 0 && seen[i+die[k]][j+dje[k]] == false)
                                q.push(pii(i+die[k], j+dje[k]));
                        }
                        else
                        {
                            flag = false;
                        }
                    }
                }
            }
            if (flag == true) 
            {
                rep(a, h)rep(b, w)
                {
                    if (seent[a][b] == true) g[a][b] = 1;
                }
            }
            else
            {
                rep(a, h)rep(b, w)
                {
                    if (seent[a][b] == true) g[a][b] = 2;
                }
            }
        }
    }
    cout<<endl;
    rep(i, h)
    {
        rep(j, w)
        {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}