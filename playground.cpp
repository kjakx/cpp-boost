#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define println(x) cout << x << endl
#define Yes println("Yes")
#define No println("No")
#define YES println("YES")
#define NO println("NO")

bool dfs(int i, int prev, vector<vector<int>>& nbl, vector<bool>& visited)
{
    if (visited[i] == true) return true;
    bool has_loop = false;
    visited[i] = true;
    for (int j : nbl[i])
    {
        if (j != prev)
        {
            has_loop |= dfs(j, i, nbl, visited);
        }
    }
    return has_loop;
}

int main()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> nbl(n);
    rep(i, m)
    {
        int u, v; cin >> u >> v;
        nbl[u-1].push_back(v-1);
        nbl[v-1].push_back(u-1);
    }
    vector<bool> visited(n, false);
    int count = 0;
    rep(i, n)
    {
        if (visited[i] == false)
        {
            bool has_loop = dfs(i, -1, nbl, visited);
            if (has_loop == false) count++;
        }
    }
    cout << count << endl;
}