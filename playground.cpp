#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    using tsii = tuple<string, int, int>;
    cin >> n;
    vector<tsii> tuples;
    for (int i = 1; i <= n; i++)
    {
        string s;
        int p;
        cin >> s;
        cin >> p;
        tuples.push_back(make_tuple(s, 100-p, i));
    }
    sort(tuples.begin(), tuples.end());
    for (auto t : tuples)
    {
        cout << get<2>(t) << endl;;
    }
}
