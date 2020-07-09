#include "header.h"

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