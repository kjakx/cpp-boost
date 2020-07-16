#include "header.h"

bool on_grid(int i, int j, int r, int c)
{
    return (i >= 0 && i < r && j >= 0 && j < c);
}

int main()
{
    int h, w; cin >> h >> w;
    vvc g(h, vc(w));
    int num_walls = 0;
    rep(i, h)
        rep(j, w)
        {
            cin >> g[i][j];
            if (g[i][j] == '#') num_walls++;
        }
    queue<pii> q;
    q.push(pii(0, 0));
    vvb seen(h, vb(w, false));
    seen[0][0] = true;
    int cnt = 0;
    bool success = false;
    while (!q.empty())
    {
        queue<pii> qt;
        while (!q.empty())
        {
            qt.push(q.front()); q.pop();
        }
        while (!qt.empty())
        {
            pii now = qt.front(); qt.pop();
            rep(i, 4)
            {
                if (on_grid(now.fi+di[i], now.sj+dj[i], h, w)
                && g[now.fi+di[i]][now.sj+dj[i]] == '.'
                && seen[now.fi+di[i]][now.sj+dj[i]] == false)
                {
                    seen[now.fi+di[i]][now.sj+dj[i]] = true;
                    q.push(pii(now.fi+di[i], now.sj+dj[i]));
                }
            }
        }
        cnt++;
        if (seen[h-1][w-1] == true) { success = true; break; }
    }
    int ans = h * w - num_walls - (cnt + 1);
    if (success) println(ans);
    else println(-1);
}