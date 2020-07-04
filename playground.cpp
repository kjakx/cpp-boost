#include <bits/stdc++.h>
// rep macro
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rev(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rev2(i, s, n) for (int i = (int)(n) - 1; i >= (int)(s); i--)
#define bitrep(i, n) for (int i = 0; i < (int)(1 << n); i++)
// vector macro
#define all(v) v.begin(), v.end()
// math macro
#define lcm(a, b) a / __gcd(a, b) * b
// print macro
#define println(x) cout << x << endl
#define Yes println("Yes")
#define No println("No")
#define YES println("YES")
#define NO println("NO")
using namespace std;
using pii = pair<int, int>;

int main()
{
  int n, m; cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> a[i][j];
  long maxtotal = 0;
  for (int i = 0; i < m - 1; i++)
    for (int j = i + 1; j < m; j++)
    {
      long total = 0;
      for (int k = 0; k < n; k++)
      {
        total += max(a[k][i], a[k][j]);
      }
      maxtotal = max(total, maxtotal);
    }
  cout << maxtotal << endl;
}