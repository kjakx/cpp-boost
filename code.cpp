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
// desc sort: sort(vec.begin(), vec.end(), greater<int>());//#include "header.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int n; cin >> n;
    vector< vector<int> > g(n, vector<int>());
    for (int i = 0; i < n; i++)
    {
        int u, k; cin >> u >> k; u--;
        for (int j = 0; j < k; j++)
        {
            int v; cin >> v; v--;
            g[i].push_back(v);
        } 
    }
    vector<bool> seen(n, false);
    vector<int> d(n, -1); d[0] = 0;
    queue<int> q;
    q.push(0);
    int depth = 0;
    while (!q.empty())
    {
        depth++;
        queue<int> qt;
        while (!q.empty())
        {
            qt.push(q.front()); 
            q.pop();
        }
        while (!qt.empty())
        {
            int x = qt.front(); qt.pop();
            seen[x] = true;
            for (int i = 0; i < g[x].size(); i++)
            {
                if(d[g[x][i]] == -1) d[g[x][i]] = depth;
                if (seen[g[x][i]] == false) q.push(g[x][i]);
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << i + 1 << " " << d[i] << endl;
}