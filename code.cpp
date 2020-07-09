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

using namespace std;

void dfs(int n, vector<vector<int>>& ki, vector<int>& c, vector<bool>& seen)
{
  if (ki[n].size() == 0) return;
  seen[n] = true;
  for (int i = 0; i < ki[n].size(); i++)
  {
    if (seen[ki[n][i]]) continue;
    c[ki[n][i]] += c[n];
    dfs(ki[n][i], ki, c, seen);
  }
}

int main()
{
  int n, q; cin >> n >> q;
  vector<vector<int>> ki(n, vector<int>());
  for (int i = 0; i < n - 1; i++)
  {
    int a, b; cin >> a >> b; a--; b--;
    ki[a].push_back(b);
    ki[b].push_back(a);
  } 
  vector<int> c(n, 0);
  for (int i = 0; i < q; i++)
  {
    int p, x; cin >> p >> x; p--;
    c[p] += x;
  }
  vector<bool> seen(n, false);
  dfs(0, ki, c, seen);
  for (int i = 0; i < n; i++)
  {
    cout << c[i];
    if (i == n - 1) cout << endl;
    else cout << " ";
  }
}