#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int max_id_under(long m, vector<long>& p)
{
    int max_id_under_m;
    int left = 0; int right = p.size() - 1;
    while (left <= right)
    {
        max_id_under_m = left + (right - left) / 2;
        if (p[max_id_under_m] == m) break;
        if (p[max_id_under_m] > m)
        {
            right = max_id_under_m - 1;
        }
        else
        {
            left = max_id_under_m + 1;
        }
    }
    return max_id_under_m;
}

int main()
{
    long n, m; cin >> n >> m;
    vector<long> p(n+1); p[0] = 0;
    rep2 (i, 1, n+1) cin >> p[i];
    sort(all(p));
    int max_id_under_m = max_id_under(m, p);
    vector<long> all_total;
    rep(i, max_id_under_m+1)
    {
        rep(j, max_id_under_m+1)
        {
            long total = p[i] + p[j];
            if (total <= m)
                all_total.push_back(total);
        }
    }
    sort(all(all_total));
    long max_total = 0;
    rep(i, all_total.size())
    {
        long total = all_total[i] + all_total[max_id_under(m - all_total[i], all_total)];
        if (total <= m)
            max_total = max(total, max_total);
    }
    cout << max_total << endl;
}