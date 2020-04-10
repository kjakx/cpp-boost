#include <bits/stdc++.h>
using namespace std;

int main()
{   
    int n, a;
    int bitsum = 0;
    int count = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        bitsum |= a;
    }
    while (!(bitsum & 1))
    {
        count++;
        bitsum >>= 1;
    }
    cout << count << endl;
}