#include "header.h"

bool on_grid(int i, int j, int r, int c)
{
    return (i >= 0 && i < r && j >= 0 && j < c);
}

int main()
{
    int h, w, n; cin >> h >> w >> n;
    vvc g(h, vc(w));
    pii s;
    vector<pii> e(n);
    rep(i, h)
        rep(j, w)
        {
            cin >> g[i][j];
            if (g[i][j] == 'S') s = pii(i, j);
            if (isdigit(g[i][j])) e[g[i][j] - '0' - 1] = pii(i, j);
        }
    
    int t = 0;
    rep(i, n)
    {
        vvb seen(h, vb(w, false));
        seen[s.fi][s.sj] = true;
        queue<pii> q;
        q.push(s);
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
                    if (on_grid(now.fi+di[i], now.sj+dj[i], h, w) 
                        && seen[now.fi+di[i]][now.sj+dj[i]] == false 
                        && g[now.fi+di[i]][now.sj+dj[i]] != 'X')
                    {
                        seen[now.fi+di[i]][now.sj+dj[i]] = true;
                        q.push(pii(now.fi+di[i], now.sj+dj[i]));
                    }
            }
            t++;
            if (seen[e[i].fi][e[i].sj] == true) break;
        }
        s = e[i];
    }
    cout << t << endl;
}