#include "header.h"
bool on_grid(int i, int j, int r, int c)
{
    return (i >= 0 && i < r && j >= 0 && j < c);
}

bool canpass(pair<int, int> from, pair<int, int> to, vector< vector<bool> >& wh, vector< vector<bool> >& wv)
{
    // horizontal move
    if (from.first == to.first)
    {
        // move left
        if (from.second > to.second)
        {
            return !wh[from.first][to.second];
        }
        // move right
        else if (from.second < to.second)
        {
            return !wh[from.first][from.second];
        }
        else return false;
    }
    // vertical move
    else if (from.second == to.second)
    {
        // move up
        if (from.first > to.first)
        {
            return !wv[to.first][from.second];
        }
        // move down
        else if (from.first < to.first)
        {
            return !wv[from.first][from.second];
        }
        else return false;
    }
    else return false;
}

int main()
{
    while (true)
    {
        int w, h; cin >> w >> h;
        if (w == 0 && h == 0) break;
        vector< vector<bool> > wh(h, vector<bool>(w - 1, false));
        vector< vector<bool> > wv(h - 1, vector<bool>(w, false));
        for (int i = 0; i < 2 * h - 1; i++)
        {
            // holizontal wall
            if (i % 2 == 0)
            {
                for (int j = 0; j < w - 1; j++)
                {
                    int c; cin >> c;
                    wh[i/2][j] = c == 1 ? true : false;
                }
            }
            // vertical wall
            else
            {
                for (int j = 0; j < w; j++)
                {
                    int c; cin >> c;
                    wv[i/2][j] = c == 1 ? true : false;
                }
            }
        }
        queue< pair<int, int> > q;
        q.push(pair<int, int>(0, 0));
        vector< vector<bool> > seen(h, vector<bool>(w, false));
        seen[0][0] = true;
        int cnt = 0;
        bool success = false;
        while (!q.empty())
        {
            queue< pair<int, int> > qt;
            while (!q.empty())
            {
                qt.push(q.front()); q.pop();
            }
            while (!qt.empty())
            {
                pair<int, int> now = qt.front(); qt.pop();
                for (int i = 0; i < 4; i++)
                {
                    if (on_grid(now.first+di[i], now.second+dj[i], h, w)
                    && seen[now.first+di[i]][now.second+dj[i]] == false
                    && canpass( now, 
                                pair<int, int>(now.first+di[i], now.second+dj[i]),
                                wh, wv ))
                    {
                        seen[now.first+di[i]][now.second+dj[i]] = true;
                        q.push(pair<int, int>(now.first+di[i], now.second+dj[i]));
                    }
                }
            }
            cnt++;
            if (seen[h-1][w-1] == true) { success = true; break; }
        }
        if (success) cout << cnt + 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}