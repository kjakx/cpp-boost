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

int r, c;
vector<vector<char>> grid;

bool on_grid(int i, int j)
{
    if (i < 0 || i >= r) return false;
    if (j < 0 || j >= c) return false;
    return true;
}

bool is_road(int i, int j)
{
    if (on_grid(i, j) == false) return false;
    if (grid[i][j] == '#') return false;
    return true;
}

void enq(queue<pii>& q, int i, int j)
{
    rep(k, 4)
    {
        if (is_road(i+di[k], j+dj[k]))
        {
            q.push(pii(i+di[k], j+dj[k]));
            grid[i+di[k]][j+dj[k]] = '#';
        }
    }
}
int main()
{
    cin >> r >> c;
    int si, sj; cin >> si >> sj; si--; sj--;
    int gi, gj; cin >> gi >> gj; gi--; gj--;
    grid = vector<vector<char>>(r, vector<char>(c));
    rep(i, r)rep(j, c)
    {
        char ch; cin >> ch;
        grid[i][j] = ch;
    }
    queue<pii> q;
    grid[si][sj] = '#';
    pii start = pii(si, sj);
    q.push(start);
    int count = 0;
    while(!q.empty())
    {
        queue<pii> q2;
        while(!q.empty())
        {
            pii p = q.front(); q.pop();
            if (p.fi == gi && p.se == gj)
            {
                println(count);
                return 0;
            }
            q2.push(p);
        }
        while(!q2.empty())
        {
            pii p = q2.front(); q2.pop();
            enq(q, p.fi, p.se);
        }
        count++;
    }
}