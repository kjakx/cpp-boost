#include "header.h"

const int dio[6] = {  1,  0, -1,  0, -1,  1};
const int djo[6] = {  0,  1,  0, -1,  1,  1};
const int die[6] = {  1,  0, -1,  0, -1,  1};
const int dje[6] = {  0,  1,  0, -1, -1, -1};

bool on_grid(int i, int j, int r, int c)
{
    return (i >= 0 && i < r && j >= 0 && j < c);
}

int main()
{
    int w, h; cin >> w >> h;
    vvi g(h, vi(w));
    rep(i, h)
        rep(j, w)
            cin >> g[i][j];
    // fill hollows
    vvb seen(h, vb(w, false));
    rep(i, h)rep(j, w)
    {
        if (g[i][j] == 0 && seen[i][j] == false)
        {
            bool flag = true;
            queue<pii> q;
            q.push(pii(i, j));
            vvb seent(h, vb(w, false));
            seen[i][j] = true;
            seent[i][j] = true;
            while (!q.empty())
            {
                pii now = q.front(); q.pop();
                if (now.fi % 2 == 0)
                {
                    rep(k, 6)
                    {   
                        if (on_grid(now.fi+dio[k], now.sj+djo[k], h, w))
                        {
                            if (g[now.fi+dio[k]][now.sj+djo[k]] == 0 && seent[now.fi+dio[k]][now.sj+djo[k]] == false)
                            {
                                seen[now.fi+dio[k]][now.sj+djo[k]] = true;
                                seent[now.fi+dio[k]][now.sj+djo[k]] = true;
                                q.push(pii(now.fi+dio[k], now.sj+djo[k]));
                            }
                        }
                        else
                        {
                            flag = false;
                        }
                    }
                }
                else
                {
                    rep(k, 6)
                    {
                        if (on_grid(now.fi+die[k], now.sj+dje[k], h, w))
                        {
                            if (g[now.fi+die[k]][now.sj+dje[k]] == 0 && seent[now.fi+die[k]][now.sj+dje[k]] == false)
                            {
                                seen[now.fi+die[k]][now.sj+dje[k]] = true;
                                seent[now.fi+die[k]][now.sj+dje[k]] = true;
                                q.push(pii(now.fi+die[k], now.sj+dje[k]));
                            }
                        }
                        else
                        {
                            flag = false;
                        }
                    }
                }
            }
            if (flag == true) 
            {
                rep(a, h)rep(b, w)
                {
                    if (seent[a][b] == true) g[a][b] = 1;
                }
            }
            else
            {
                rep(a, h)rep(b, w)
                {
                    if (seent[a][b] == true) g[a][b] = -1;
                }
            }
        }
    }
    int cnt = 0;
    vvb seen2(h, vb(w, false));
    rep(i, h)rep(j, w)
    {
        if (g[i][j] == 1 && seen2[i][j] == false)
        {
            queue<pii> q;
            q.push(pii(i, j));
            vvb seent2(h, vb(w, false));
            seen2[i][j] = true;
            while (!q.empty())
            {
                pii now = q.front(); q.pop();
                int nbr = 0;
                if (now.fi % 2 == 0)
                {
                    rep(k, 6)
                    {   
                        if (on_grid(now.fi+dio[k], now.sj+djo[k], h, w) && g[now.fi+dio[k]][now.sj+djo[k]] == 1)
                        {
                            nbr++;
                            if (seen2[now.fi+dio[k]][now.sj+djo[k]] == false)
                            {
                                seen2[now.fi+dio[k]][now.sj+djo[k]] = true;
                                q.push(pii(now.fi+dio[k], now.sj+djo[k]));
                            }
                        }
                    }
                }
                else
                {
                    rep(k, 6)
                    {
                        if (on_grid(now.fi+die[k], now.sj+dje[k], h, w) && g[now.fi+die[k]][now.sj+dje[k]] == 1)
                        {
                            nbr++;
                            if (seen2[now.fi+die[k]][now.sj+dje[k]] == false)
                            {
                                seen2[now.fi+die[k]][now.sj+dje[k]] = true;
                                q.push(pii(now.fi+die[k], now.sj+dje[k]));
                            }
                        }
                    }
                }
                cnt += 6 - nbr;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}