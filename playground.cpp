#include <bits/stdc++.h>
using namespace std;
// rep macro
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rev(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rev2(i, s, n) for (int i = (int)(n) - 1; i >= (int)(s); i--)
#define bitrep(i, n) for (int i = 0; i < (int)(1 << n); i++)
// vector macro
#define all(v) v.begin(), v.end()
// math macro
#define lcm(a, b) a / __gcd(a, b) * b
// print macro
#define println(x) cout << x << endl
#define Yes println("Yes")
#define No println("No")
#define YES println("YES")
#define NO println("NO")
// pair macro
#define x first
#define y second
using pii = pair<int, int>;
using pdd = pair<double, double>;

pii adj(pii src, pii mv)
{
    return pii(src.x + mv.x, src.y + mv.y);
}

int main()
{
    int m; cin >> m;
    vector<pii> p(m);
    rep(i, m) { cin >> p[i].x >> p[i].y; }
    int n; cin >> n;
    vector<pii> q(n);
    rep(i, n) { cin >> q[i].x >> q[i].y; }
    sort(all(p));
    sort(all(q));
    pii mv;
    for (int i = 0; i < n; i++)
    {
        mv = pii(q[i].x - p[0].x, q[i].y - p[0].y);
        bool success = true;
        for (int j = 1; j < m; j++)
        {
            pii r = adj(p[j], mv);
            if (*lower_bound(all(q), r) != r)
            {
                success = false;
                break;
            }
        }  
        if (success) break;
    }
    cout << mv.x << " " << mv.y << endl;
}