#include "header.h"
#include <iostream>
#include <vector>
using namespace std;

bool ongrid(int h, int w, vector< vector<int> >& g)
{
    if (h >= 0 && h < g.size() && w >= 0 && w < g[0].size()) return true;
    return false;
}

bool dfs(int h, int w, vector< vector<int> >& g, vector< vector<bool> >& seen)
{
    seen[h][w] = true;
    if (g[h][w] == 0) return false;
    for (int i = 0; i < 8; i++)
    {
        if (ongrid(h+di[i], w+dj[i], g) && seen[h+di[i]][w+dj[i]] == false)
            dfs(h+di[i], w+dj[i], g, seen);
    }
    return true;
}

int main()
{
    while (true)
    {
        int w, h; cin >> w >> h;
        if (w == 0 && h == 0) break;
        vector< vector<int> > g(h, vector<int>(w));
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                { int c; cin >> c; g[i][j] = c;}
        vector< vector<bool> > seen(h, vector<bool>(w, false));
        int cnt = 0;
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                if (seen[i][j] == false)
                    if (dfs(i, j, g, seen) == true) cnt++;
        cout << cnt << endl;
    }
}