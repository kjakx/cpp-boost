#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin >> s;
    int max_op_num = (int)(s.size() - 1);
    long sum = 0;
    for (int tmp = 0; tmp < (1 << max_op_num); tmp++)
    {
        bitset<9> bs(tmp);
        string tmp_s = s;
        for (int i = 9; i >= 1; i--)
        {
            if (bs.test(i-1) == true)
            {
                sum += stol(tmp_s.substr(i));
                tmp_s.erase(i);
            }
        }
        sum += stol(tmp_s);
    }
    cout << sum << endl;
}