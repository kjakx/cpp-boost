#include <bits/stdc++.h>
using namespace std;

int count_friends(vector<int>&, int);
int n, m;
int ans = 0;
vector<vector<bool>> are_friends;

int main()
{
    cin >> n >> m;
    are_friends.resize(n, vector<bool>(n, false));
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        are_friends[x - 1][y - 1] = true;
        are_friends[y - 1][x - 1] = true;
    }
    vector<int> friends;
    int max_friend_num = count_friends(friends, 0);
    cout << max_friend_num << endl;
}

int count_friends(vector<int>& friends, int depth)
{
    if (depth == n)
    {
        for (int i = 0; i < int(friends.size()) - 1; i++)
        {
            for (int j = i + 1; j < int(friends.size()); j++)
            {
                if (!are_friends[friends[i]][friends[j]]) return 0;
            }
        }
        ans = max(ans, int(friends.size()));
        // cout << ans << endl;
    }
    else
    {
        ans = max(ans, count_friends(friends, depth+1));
        friends.push_back(depth);
        ans = max(ans, count_friends(friends, depth+1));
        friends.pop_back();
    }
    return ans;
}