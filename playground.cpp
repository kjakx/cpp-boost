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

int h, w;

bool on_grid(int i, int j)
{
    if (i < 0 || i >= h) return false;
    if (j < 0 || j >= w) return false;
    return true;
}

bool is_road(int i, int j, vector<vector<char>>& grid)
{
    if (on_grid(i, j) == false) return false;
    if (grid[i][j] == 'X') return false;
    return true;
}

int main()
{
    int n;
    cin >> h >> w >> n;
    pii s;
    vector<pii> gv(n);
    vector<vector<char>> grid(h, vector<char>(w));
    vector<vector<int>> t(h, vector<int>(w, -1));
    rep(i, h)rep(j, w)
    {
        char ch; cin >> ch;
        if (isdigit(ch)) gv[ch - '0' - 1] = pii(i, j);
        else if (ch == 'S') { s = pii(i, j); }
        grid[i][j] = ch;
    }
    int cnt = 0;
    for (pii g : gv)
    {
        queue<pii> q; q.push(s);
        vector<vector<int>> tm = t;
        tm[s.fi][s.se] = 0; 
        while (!q.empty())
        {
            pii p = q.front(); q.pop();
            if (p == g) break;
            rep(k, 4)
            {
                if (is_road(p.fi+di[k], p.se+dj[k], grid) && tm[p.fi+di[k]][p.se+dj[k]] == -1)
                {
                    q.push(pii(p.fi+di[k], p.se+dj[k]));
                    tm[p.fi+di[k]][p.se+dj[k]] = tm[p.fi][p.se] + 1;
                }
            }
        }
        cnt += tm[g.fi][g.se];
        s = pii(g.fi, g.se);
    }
    cout << cnt << endl;
}