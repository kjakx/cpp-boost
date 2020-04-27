#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main()
{
    int n, y;
    cin >> n >> y;
    rep(i, n + 1)
    {
        rep(j, n + 1 - i)
        {
            int y_tmp = y;
            y_tmp -= i * 10000;
            y_tmp -= j * 5000;
            if (y_tmp >= 0 && i + j + (y_tmp / 1000) == n)
            {
                cout << i << " " << j << " " << (y_tmp / 1000) << endl;
                return 0;
            }
        }
    }
    cout << "-1 -1 -1" << endl;
}