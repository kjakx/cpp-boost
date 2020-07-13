#include "header.h"

bool ongrid(int h, int w, vector< vector<int> >& g)
{
    if (h >= 0 && h < (int)g.size() && w >= 0 && w < (int)g[0].size()) return true;
    return false;
}

int dfs(int n, int h, int w, vector< vector<int> >& g, vector< vector<bool> >& seen)
{
    n++;
    seen[h][w] = true;
    int ret = n;
    for (int i = 0; i < 4; i++)
        if (ongrid(h+di[i], w+dj[i], g) && seen[h+di[i]][w+dj[i]] == false && g[h+di[i]][w+dj[i]] == 1)
            ret = max(dfs(n, h+di[i], w+dj[i], g, seen), ret);
    seen[h][w] = false;
    return ret;
}

int main()
{
    int w, h; cin >> w >> h;
    vector< vector<int> > g(h, vector<int>(w));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            { int c; cin >> c; g[i][j] = c;}
    int cnt = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
        {
            vector< vector<bool> > seen(h, vector<bool>(w, false));
            if (g[i][j] == 1)
                cnt = max(dfs(0, i, j, g, seen), cnt);
        }
    cout << cnt << endl;
}