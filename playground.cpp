#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define println(x) cout << x << endl

int h, w;
vector<vector<char>> grid;

bool isroad(int i, int j)
{
    if (i < 0 || i >= h) return false;
    if (j < 0 || j >= w) return false;
    if (grid[i][j] == '#') return false;
    return true;
}

bool dfs(int i, int j)
{
    if (grid[i][j] == 'g') return true;
    bool res = false;
    grid[i][j] = '#';
    if (res == false && isroad(i-1, j)) res |= dfs(i-1, j);
    if (res == false && isroad(i, j+1)) res |= dfs(i, j+1);
    if (res == false && isroad(i+1, j)) res |= dfs(i+1, j);
    if (res == false && isroad(i, j-1)) res |= dfs(i, j-1);
    //grid[i][j] = '.';
    return res;
}

int main()
{
    cin >> h >> w;
    grid.resize(h, vector<char>(w));
    int si, sj;
    rep(i, h)
    {
        rep(j, w)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 's')
            {
                si = i;
                sj = j;
            }
        }
    }
    bool res = dfs(si, sj);
    if (res == true) cout << "Yes" << endl;
    else             cout << "No"  << endl;
}