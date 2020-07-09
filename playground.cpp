#include "header.h"

int main()
{
    int n; cin >> n;
    vi a(n), b(n), c(n); 
    rep(i, n) cin >> a[i]; rep(i, n) cin >> b[i]; rep(i, n) cin >> c[i];
    sort(all(a));sort(all(b));sort(all(c));
    // max of sum : (10^5)^3 = 10^15
    ll sum = 0;
    auto ib = b.begin();
    // O(nlogn)
    while (ib != b.end())
    {
        auto ia = lower_bound(all(a), *ib);
        auto ic = upper_bound(all(c), *ib);
        sum += (ia - a.begin()) * (c.end() - ic);
        ib++;
    }
    cout << sum << endl;
}