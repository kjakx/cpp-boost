#include <bits/stdc++.h>
using namespace std;

void print_seven(string& n);
bool eq_seven(string& n, char op, string eq, int val, int depth);

int main()
{
    string n;
    cin >> n;
    print_seven(n);
    return 0;
}

bool eq_seven(string& n, char op, string eq, int val, int depth)
{
    bool found = false;
    if (depth == 0)
    {
        val = n[0] - '0';
        eq += n[0];
    }
    depth++;
    if (op == '+')
    {
        val += n[depth] - '0';
        eq += "+";
        eq += n[depth];
    }
    if (op == '-')
    {
        val -= n[depth] - '0';
        eq += "-";
        eq += n[depth];
    }
    if (depth == 3)
    {
        if (val == 7)
        {
            cout << eq << "=7" << endl;
            found |= true;
        }
    }
    else
    {
        if (found) return true;
        found |= eq_seven(n, '+', eq, val, depth);
        if (found) return true;
        found |= eq_seven(n, '-', eq, val, depth);      
    }
    return found;
}

void print_seven(string& n)
{
    if(!eq_seven(n, '+', "", 0, 0)) 
        eq_seven(n, '-', "", 0, 0);
}