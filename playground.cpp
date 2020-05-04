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

struct Robot
{
    int x;
    int s;
    int t;
    Robot(int x, int l)
    {
        x = x;
        s = x - l;
        t = x + l;
    }
    bool covers(Robot& r1)
    {
        return t > r1.s;
    }
};

bool operator<(const Robot& r1, const Robot& r2)
{
    return r1.t < r2.t;
}

int main()
{
    int n;
    cin >> n;
    vector<Robot> vr;
    rep(i, n)
    {
        int x, l;
        cin >> x >> l;
        Robot r = Robot(x, l);
        vr.push_back(r);
    }
    sort(all(vr));
    int count = n;
    Robot prev = vr[0];
    rep2(i, 1, n)
    {
        if (prev.covers(vr[i])) count--;
        else prev = vr[i];
    }
    println(count);
}