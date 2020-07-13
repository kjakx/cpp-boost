#include "header.h"

void dfs(int n, vector< vector<int> >& ki, vector<int>& c, vector<bool>& seen)
{
    seen[n] = true;
    rep(i, ki[n].size())
    {
        if (seen[ki[n][i]] == false)
        {
            c[ki[n][i]] += c[n];
            dfs(ki[n][i], ki, c, seen);
        }
    }
}

int main()
{
    int n, q; cin >> n >> q;
    vector< vector<int> > ki(n, vector<int>());
    rep(i, n - 1)
    {
        int a, b; cin >> a >> b; a--; b--; 
        ki[a].push_back(b);
        ki[b].push_back(a);
    }
    vector<int> c(n, 0);
    rep(i, q)
    {
        int p, x; cin >> p >> x; p--;
        c[p] += x;
    }
    vector<bool> seen(n, false);
    dfs(0, ki, c, seen);
    rep(i, n)
    {
        cout << c[i];
        if (i == n - 1) cout << endl;
        else cout << " ";
    }
}