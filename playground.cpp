#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define println(x) cout << x << endl
#define Yes println("Yes")
#define No println("No")
#define YES println("YES")
#define NO println("NO")

int island_area;
vector<vector<char>> grid(10, vector<char>(10));

bool on_grid(int i, int j)
{
    if (i < 0 || i >= 10) return false;
    if (j < 0 || j >= 10) return false;
    return true;
}

bool is_island(int i, int j)
{
    if (on_grid(i, j) == false) return false;
    if (grid[i][j] == 'x') return false;
    return true;
}

int dfs(int i, int j, vector<vector<bool>>& visited)
{
    if (visited[i][j] == true) return 0;
    int count = 1;
    visited[i][j] = true;
    if (is_island(i-1, j)) count += dfs(i-1, j, visited);
    if (is_island(i, j+1)) count += dfs(i, j+1, visited);
    if (is_island(i+1, j)) count += dfs(i+1, j, visited);
    if (is_island(i, j-1)) count += dfs(i, j-1, visited);
    return count;
}

int main()
{
    island_area = 0;
    rep(i, 10)
    {
        rep(j, 10)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'o') island_area++;
        }
    }
    rep(i, 10)
    {
        rep(j, 10)
        {
            if (grid[i][j] == 'x')
            {
                vector<vector<bool>> visited(10, vector<bool>(10, false));
                int count = dfs(i, j, visited);
                if (count == island_area + 1)
                {
                    YES; return 0;
                }
            }
        }
    }
    NO; return 0;
}