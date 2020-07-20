#include "header.h"

int main()
{
    int n, wm; cin >> n >> wm;
    vector<int> v(n);
    vector<int> w(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i] >> w[i];
    }
    vector< vector<int> > dp(n+1, vector<int>(wm+1, 0));
    for (int i = 0; i < n; i++)
    {
        for (int wi = 0; wi <= wm; wi++)
        {
            if (wi >= w[i])
                dp[i+1][wi] = max(dp[i][wi - w[i]] + v[i], dp[i][wi]);
            else
                dp[i+1][wi] = dp[i][wi];
        }
    }
    cout << dp[n][wm] << endl;
    return 0;
}