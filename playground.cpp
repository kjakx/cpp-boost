//#include "header.h"
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N, W; cin >> N >> W;
    vector<int> v(N), w(N);
    for (int i = 0; i < N; i++)
        cin >> v[i] >> w[i];
    vector<int> dp(W+1, 0);
    for (int i = 1; i <= W; i++)
        for (int j = 0; j < N; j++)
            if (w[j] <= i)
                dp[i] = max(dp[i-w[j]]+v[j], dp[i]);

    cout << dp[W] << endl;
    return 0;
}