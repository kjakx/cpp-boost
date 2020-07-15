#include "header.h"
#include <cmath>
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
    
    vvb seen(h, vb(w, false));
    rep(i, h)rep(j, w)
    {
        if (g[i][j] == 0 && seen[i][j] == false)
        {
            bool flag = true;
            queue<pii> q;
            q.push(pii(i, j));
            vvb seent(h, vb(w, false));
            while (!q.empty())
            {
                pii now = q.front(); q.pop();
                seen[now.fi][now.sj] = true;
                seent[now.fi][now.sj] = true;
                if (now.fi % 2 == 0)
                {
                    rep(k, 6)
                    {   
                        if (on_grid(i+dio[k], j+djo[k], h, w))
                        {
                            if (g[i+dio[k]][j+djo[k]] == 0 && seen[i+dio[k]][j+djo[k]] == false)
                                q.push(pii(i+dio[k], j+djo[k]));
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
                        if (on_grid(i+die[k], j+dje[k], h, w))
                        {
                            if (g[i+die[k]][j+dje[k]] == 0 && seen[i+die[k]][j+dje[k]] == false)
                                q.push(pii(i+die[k], j+dje[k]));
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
                    if (seent[a][b] == true) g[a][b] = 2;
                }
            }
        }
    }
    cout<<endl;
    rep(i, h)
    {
        rep(j, w)
        {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}