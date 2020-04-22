#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> t(n);
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
    }
    int min_time = 100000001;
    for (int tmp = 0; tmp < (1 << n); tmp++)
    {
        int time = 0;
        int t1 = 0, t2 = 0;
        bitset<4> bs(tmp);
        for (int i = 0; i < n; i++)
        {
            if (bs.test(i) == true)
            {
                t1 += t[i];
            }
            else
            {
                t2 += t[i];
            }
        }
        time = max(t1, t2);
        min_time = min(time, min_time);
    }
    cout << min_time << endl;
}