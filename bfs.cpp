#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define println(x) cout << x << endl
#define fi first
#define se second
#define Yes println("Yes")
#define No println("No")
#define YES println("YES")
#define NO println("NO")
const int di[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dj[8] = {0, 1, 0, -1, -1, 1, 1, -1};

using pii = pair<int, int>;

bool on_grid(int i, int j, vector<vector<char>>& grid)
{
    if (i < 0 || i >= grid.size()) return false;
    if (j < 0 || j >= grid[i].size()) return false;
    return true;
}

bool is_road(int i, int j, vector<vector<char>>& grid)
{
    if (on_grid(i, j, grid) == false) return false;
    if (grid[i][j] == '#') return false;
    return true;
}

bool is_wall(int i, int j, vector<vector<char>>& grid)
{
    if (on_grid(i, j, grid) == false) return false;
    if (grid[i][j] == '#') return true;
    return false;
}

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<char>> grid(h, vector<char>(w));
    vector<vector<int>> hp(h, vector<int>(w, -1));
    queue<pii> q;
    pii g;
    rep(i, h)rep(j, w)
    {
        char ch; cin >> ch;
        if (ch == 's') 
        {
            q.push(pii(i, j));
            hp[i][j] = 2;
        }
        if (ch == 'g')
        {
            g = pii(i, j);
        }
        grid[i][j] = ch;
    }
    while (!q.empty())
    {
        pii p = q.front(); q.pop();
        if (p == g) break;
        rep(k, 4)
        {
            if (is_road(p.fi+di[k], p.se+dj[k], grid))
            {
                if (hp[p.fi+di[k]][p.se+dj[k]] < hp[p.fi][p.se])
                {
                    q.push(pii(p.fi+di[k], p.se+dj[k]));
                    hp[p.fi+di[k]][p.se+dj[k]] = hp[p.fi][p.se];
                }
            }
            else if (is_wall(p.fi+di[k], p.se+dj[k], grid))
            {
                if (hp[p.fi][p.se] > 0 && hp[p.fi+di[k]][p.se+dj[k]] < hp[p.fi][p.se] - 1)
                {
                    q.push(pii(p.fi+di[k], p.se+dj[k]));
                    hp[p.fi+di[k]][p.se+dj[k]] = hp[p.fi][p.se] - 1;
                }
            }
        }
    }
    /* print hp on grid
    rep(i, h)
    {
        rep(j, w)
        {
            if (hp[i][j] == -1) cout << 'X';
            else cout << hp[i][j];
        }
        cout << endl;
    }
    */
    if (hp[g.fi][g.se] >= 0) YES;
    else NO;
}