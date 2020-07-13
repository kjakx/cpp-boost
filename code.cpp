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
// desc sort: sort(vec.begin(), vec.end(), greater<int>());#include "header.h"
#include <iostream>
#include <vector>
using namespace std;

bool ongrid(int h, int w, vector< vector<int> >& g)
{
    if (h >= 0 && h < g.size() && w >= 0 && w < g[0].size()) return true;
    return false;
}

int dfs(int n, int h, int w, vector< vector<int> >& g, vector< vector<bool> >& seen)
{
    n++;
    seen[h][w] = true;
    int ret = n;
    for (int i = 0; i < 4; i++)
    {
        if (ongrid(h+di[i], w+dj[i], g) && seen[h+di[i]][w+dj[i]] == false && g[h+di[i]][w+dj[i]] == 1)
            ret = max(dfs(n, h+di[i], w+dj[i], g, seen), ret);
    }
    return ret;
}

int main()
{
    int w, h; cin >> w >> h;
    vector< vector<int> > g(h, vector<int>(w));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            { int c; cin >> c; g[i][j] = c;}
    int cnt = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
        {
            if (g[i][j] == 1) 
            {
                vector< vector<bool> > seen(h, vector<bool>(w, false));
                cnt = max(dfs(0, i, j, g, seen), cnt);
            }
        }
    cout << cnt << endl;
}