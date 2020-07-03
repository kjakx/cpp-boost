#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rev(i, n) for (int i = (int)(n - 1); i >= 0; i--)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rev2(i, s, n) for (int i = (int)(n) - 1; i >= (int)(s); i--)
#define bitrep(i, n) for (int i = 0; i < (int)(1 << n); i++)
#define all(v) v.begin(), v.end()
#define println(x) cout << x << endl
#define fi first
#define se second
#define Yes println("Yes")
#define No println("No")
#define YES println("YES")
#define NO println("NO")
using pii = pair<int, int>;

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    vector<vector<int>> x(n, vector<int>());
    vector<vector<int>> y(n, vector<int>());
    rep(i, n)
    {
        cin >> a[i];
        rep(j, a[i])
        {
            int xij, yij; cin >> xij >> yij;
            x[i].push_back(xij - 1); y[i].push_back(yij);
        }
    }
    int maxhon = 0;
    bitrep(t, n)
    {
        set<int> s;
        bitset<15> bs(t);
        bool inconsistent = false;
        rep(i, n)
        {
            if (bs[i] == 1)
            {
                s.insert(i);
                rep(j, a[i])
                {
                    if (y[i][j] == 1)
                    {
                        if (bs[x[i][j]] == 1)
                        {
                            s.insert(x[i][j]);
                        }
                        else
                        {
                            s.clear();
                            inconsistent = true;
                            break;
                        }
                    }
                    else
                    {
                        if (bs[x[i][j]] == 1)
                        {
                            s.clear();
                            inconsistent = true;
                            break;
                        }
                    }
                }
            }
            if (inconsistent) break;
        }
        maxhon = max((int)s.size(), maxhon);
    }
    cout << maxhon << endl;
}