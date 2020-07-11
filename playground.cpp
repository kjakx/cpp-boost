#include "header.h"
#include <iostream>
#include <vector>
using namespace std;

void dfs(int n, int &t, vector< vector<int> >& g, vector<int>& d, vector<int>& f, vector<bool>& seen)
{
    t++;
    if (d[n] == 0) d[n] = t;
    seen[n] = true;
    for (int i = 0; i < g[n].size(); i++)
    {
        if (seen[g[n][i]]) continue;
        dfs(g[n][i], t, g, d, f, seen);
    }
    t++;
    f[n] = t;
}

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
            g[u].push_back(v);
        }
    } 
    vector<int> d(n, 0);
    vector<int> f(n, 0);
    vector<bool> seen(n, false);
    int t = 0;
    for (int i = 0; i < n; i++)
        if (seen[i] == false)
            dfs(i, t, g, d, f, seen);
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " " <<  d[i] << " " << f[i] << endl;
    }
}