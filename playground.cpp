#include <bits/stdc++.h>
#include <climits>
using namespace std;
// rep macro
#define rep(i, n)        for (int i = 0; i < (int)(n); i++)
#define rev(i, n)        for (int i = (int)(n - 1); i >= 0; i--)
#define rep2(i, s, n)    for (int i = (s); i < (int)(n); i++)
#define rev2(i, s, n)    for (int i = (int)(n) - 1; i >= (int)(s); i--)
#define bitrep(i, n)     for (int i = 0; i < (1 << (int)(n)); i++)
#define bitrep2(i, s, n) for (int i = (s); i < (1 << (int)(n)); i++)
// vector macro
#define all(v) v.begin(), v.end()
using vi  = vector<int>;
using vvi = vector<vector<int>>;
using vl  = vector<long>;
using vvl = vector<vector<long>>;
using vb  = vector<bool>;
using vvb = vector<vector<bool>>;
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
// memo
// desc sort: sort(vec.begin(), vec.end(), greater<int>());

double dist(pii a, pii b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main()
{
    int n; cin >> n;
    vi I(n); iota(all(I), 0);
    vi a(n), b(n); rep(i, n) cin >> a[i] >> b[i];
    double sum = 0;
    int cnt = 0;
    do {
        rep(i, n - 1) sum += dist(pii(a[I[i]], b[I[i]]), pii(a[I[i+1]], b[I[i+1]]));
        cnt++;
    } while (next_permutation(all(I)));
    cout << fixed << setprecision(10) << sum / cnt << endl;
}