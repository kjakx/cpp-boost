//#include "header.h"
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