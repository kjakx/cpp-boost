#include <bits/stdc++.h>
using namespace std;

int main()
{
    char c[4];
    cin >> c;
    int sum = c[0] - '0';
    char eq[9];
    eq[0] = c[0];
    for (int tmp = 0; tmp < (1 << 3); tmp++)
    {
        bitset<3> bs(tmp);
        for (int i = 0; i < 3; i++)
        {
            if (bs.test(i) == true)
            {
                sum += c[i+1] - '0';
                eq[2*i+1] = '+';
                eq[2*i+2] = c[i+1];
            }
            else
            {
                sum -= c[i+1] - '0';
                eq[2*i+1] = '-';
                eq[2*i+2] = c[i+1];
            }
        }
        if (sum == 7) 
        {
            eq[7] = '='; eq[8] = '7';
            break;
        }
        else
        {
            sum = c[0] - '0';
        }
    }
    for (int i = 0; i < 9; i++)
    {
        cout << eq[i];
    }
    cout << endl;
}