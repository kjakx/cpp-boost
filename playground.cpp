#include <bits/stdc++.h>
using namespace std;

int min_time(vector<bool>, int);
int n;
int max_time;
vector<int> t;

int main()
{
    cin >> n;
    t.resize(n);
    max_time = 0;
    for (int i = 0; i < n; i++) 
    {
        cin >> t[i];
        max_time += t[i];
    }
    vector<bool> flags(n, false);
    int time = max_time;
    time = min_time(flags, 0);
    flags[0] = true;
    time = min(time, min_time(flags, 0));
    cout << time << endl;
}

int min_time(vector<bool> flags, int depth)
{
    int m1_time = 0, m2_time = 0;
    for (int i = 0; i < n; i++)
    {
        if (flags[i] == true)
            m1_time += t[i];
        else
            m2_time += t[i];
    }
    int time = max(m1_time, m2_time);
    for (int i = depth + 1; i < n; i++)
    {
        time = min(time, min_time(flags, i));
        flags[i] = true;
        time = min(time, min_time(flags, i));
        flags[i] = false;
    }
    return time;
}