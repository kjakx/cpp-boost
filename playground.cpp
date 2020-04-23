#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> arefriends(n, vector<bool>(n, false));
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        arefriends[x-1][y-1] = true;
        arefriends[y-1][x-1] = true;
    }
    int max_friends = 1;
    for (int tmp = 0; tmp < (1 << n); tmp++)
    {
        bitset<12> bs(tmp);
        int i, j;
        int areallfriends = true;
        for (i = 0; i < n - 1; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (bs.test(i) && bs.test(j))
                {
                    if (arefriends[i][j] == false) 
                    {
                        areallfriends = false;
                        break;
                    }
                }
            }
            if (areallfriends == false) break;
        }
        if (areallfriends == true) 
            max_friends = max((int)bs.count(), max_friends);
    }
    cout << max_friends << endl;
}