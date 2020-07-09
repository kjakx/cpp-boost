#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <numeric>
//#include <bits/stdc++.h>
#include <climits>
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
// vector macro
#define all(v) v.begin(), v.end()
using  vi = vector<int>;
using vvi = vector<vector<int>>;
using  vl = vector<long>;
using vvl = vector<vector<long>>;
using  vb = vector<bool>;
using vvb = vector<vector<bool>>;
using  vc = vector<char>;
using vvc = vector<vector<char>>;
using  vs = vector<string>;
using vvs = vector<vector<string>>;
// math macro
#define lcm(a, b) a / __gcd(a, b) * b
// print macro
#define println(x) cout << x << endl
#define Yes println("Yes")
#define No println("No")
#define YES println("YES")
#define NO println("NO")
// pair macro
#define fi first
#define sj second
using pii = pair<int, int>;
using pdd = pair<double, double>;
// memo
// desc sort: sort(vec.begin(), vec.end(), greater<int>());
#include <iostream>
#include <vector>

bool on_board(pii p)
{
    return (p.fi >= 0 && p.fi < 8 && p.sj >= 0 && p.sj < 8);
}
bool chk(vvc& b)
{
    bool res = true;
    vector<pii> q;
    // vertical and horizontal 
    rep(i, 8)
        rep(j, 8)
            if (b[i][j] == 'Q') q.push_back(pii(i, j));
    for (auto p : q)
    {
        for (int i = 0; i < 8; i++)
        {
            pii now;
            now = p;
            while(on_board(pii(now.fi+di[i], now.sj+dj[i])))
            {
                now.fi += di[i];
                now.sj += dj[i];
                if (b[now.fi][now.sj] == 'Q')
                {
                    res = false;
                    break;
                }
            }
            if (res == false) break;
        }
        if (res == false) break;
    }
    return res;
}
void print_board(vvc& b)
{
    rep(i, 8)
    {
        rep(j, 8)
        {
            cout << b[i][j];
        }
        cout << endl;
    }
}
int main()
{
    int k; cin >> k;
    vector<pii> q(k);
    rep(i, k) cin >> q[i].fi >> q[i].sj;
    vi I(8); iota(all(I), 0);
    bool res;
    do
    {
        vvc b(8, vc(8, '.'));
        rep(i, 8)
        {
            b[i][I[i]] = 'Q';
        }
        bool skip = false;
        for(auto p : q)
        {
            if (b[p.fi][p.sj] != 'Q') 
            {
                skip = true;
                break;
            }
        }
        if (skip) continue;
        res = chk(b);
        if (res == true)
        {
            print_board(b);
            break;
        }
    } while (next_permutation(all(I)));
}