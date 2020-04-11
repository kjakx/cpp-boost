#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c; cin >> a >> b >> c;
    int noppo = max(a, max(b, c));
    int chibi = min(a, min(b, c));
    cout << noppo - chibi << endl;
}
