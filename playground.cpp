#include "header.h"

int main()
{
    int n; cin >> n;
    vi a(n), b(n), c(n); rep(i, n) cin >> a[i];rep(i, n) cin >> b[i];rep(i, n) cin >> c[i];
    sort(all(a));
    sort(all(b));
    sort(all(c));
    int sum = 0;
    auto itr_ua = a.begin();
    // O(n)
    while (itr_ua != a.end())
    {
        auto lb = upper_bound(all(b), *itr_ua);
        if (lb == b.end()) break;
        auto itr_ub = lb;
        // O(n)
        while (itr_ub != b.end())
        {
            auto lc = upper_bound(all(c), *itr_ub);
            if (lc == c.end()) break;
            sum += c.end() - lc;
            itr_ub++;
        }
        itr_ua++;
    }
    cout << sum << endl;
}