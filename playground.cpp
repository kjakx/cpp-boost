#include <bits/stdc++.h>
using namespace std;

bool is_reachable(vector<vector<char>>&, vector<vector<bool>>&, int, int, const int&, const int&);
bool within_map(int i, int j, const int h, const int w);

int main()
{
    int h, w;
    cin >> h;
    cin >> w;
    vector<vector<char>> map(h, vector<char>(w));
    int start_i, start_j;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 's')
            {
                start_i = i;
                start_j = j;
            };
        }
    }
    vector<vector<bool>> visited(h, vector<bool>(w, false));
    if (is_reachable(map, visited, start_i, start_j, h, w))
    {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}

bool is_reachable(vector<vector<char>>& map, vector<vector<bool>>& visited, int i, int j, const int& h, const int& w)
{
    if (map[i][j] == 'g') return true;
    visited[i][j] = true;
    bool reachable = false;
    if (within_map(i-1, j, h, w) && map[i-1][j] != '#' && visited[i-1][j] == false)
    {
        reachable |= is_reachable(map, visited, i-1, j, h, w);
    }
    if (within_map(i+1, j, h, w) && map[i+1][j] != '#' && visited[i+1][j] == false)
    {
        reachable |= is_reachable(map, visited, i+1, j, h, w);
    }
    if (within_map(i, j-1, h, w) && map[i][j-1] != '#' && visited[i][j-1] == false)
    {
        reachable |= is_reachable(map, visited, i, j-1, h, w);
    }
    if (within_map(i, j+1, h, w) && map[i][j+1] != '#' && visited[i][j+1] == false)
    {
        reachable |= is_reachable(map, visited, i, j+1, h, w);
    }
    return reachable;
}

bool within_map(int i, int j, const int h, const int w)
{
    if (i < 0 || i >= h || j < 0 || j >= w) return false;
    return true;
}