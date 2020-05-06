#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define println(x) cout << x << endl
#define fi first
#define se second
#define Yes println("Yes")
#define No println("No")
#define YES println("YES")
#define NO println("NO")
using pii = pair<int, int>;

struct BIT
{
    vector<int> bit;
    int n;

    BIT(int n): bit(vector<int>(n+1, 0)), n(n) {}

    int query(int i)
    {
        int ret = 0;
        while(i > 0)
        {
            ret = max(ret, bit[i]);
            i -= i&(-i);
        }
        return ret;
    }

    void update(int i, int x)
    {
        while(i <= n)
        {
            bit[i] = max(x, bit[i]);
            i += i&(-i);
        }
    }
};

int main()
{
    int n;
    cin >> n;
    vector<pii> vb;
    rep(i, n)
    {
        int h, w;
        cin >> h >> w;
        vb.push_back(pii(h, w));
    }
    sort(all(vb), 
        [](pii& p1, pii& p2)
        {
            if (p1.fi == p2.fi) return p1.se > p2.se;
            else return p1.fi < p2.fi;
        });
    vector<int> count(n);
    BIT bit = BIT(100000);
    rep(i, n)
    {
        count[i] = bit.query(vb[i].se - 1) + 1;
        bit.update(vb[i].se, count[i]);
    }
    int max_count = 0;
    rep(i, n)
    {
        max_count = max(count[i], max_count);
    }
    println(max_count);
}