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

struct Range
{
    int l;
    int r;
    Range(int l, int r)
    {
        this->l = l;
        this->r = r;
    }
    bool covers(Range& r1)
    {
        return r > r1.l;
    }
};

bool operator<(const Range& r1, const Range& r2)
{
    return r1.r < r2.r;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<Range> vr;
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        Range r = Range(a, b);
        vr.push_back(r);
    }
    sort(all(vr));
    int count = 1;
    Range prev = vr[0];
    rep2(i, 1, m)
    {
        if (prev.covers(vr[i])) continue;
        else
        {
            prev = vr[i];
            count++;
        }
    }
    println(count);
}