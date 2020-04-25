#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main()
{
    int n, k; cin >> n >> k;
    vector<string> cards(n);
    rep (i, n) cin >> cards[i];
    sort(all(cards));
    set<int> s;
    do
    {
        string s_tmp = "";
        rep (i, k) s_tmp += cards[i];
        s.insert(stoi(s_tmp));
    } while(next_permutation(all(cards)));
    cout << s.size() << endl;
}