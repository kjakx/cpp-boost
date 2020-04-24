#include <bits/stdc++.h>
#include <stdexcept>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()

// 問題文の形式でvec値を出力
void print_vec(vector<int> vec) {
  cout << "[ ";
  for (int i = 0; i < vec.size(); i++) {
    cout << vec.at(i) << " ";
  }
  cout << "]" << endl;
}

void add_vec(vector<int>& a, vector<int>& b)
{
    for (int i = 0; i < a.size(); i++)
    {
        a[i] += b[i];
    }
}

void sub_vec(vector<int>& a, vector<int>& b)
{
    for (int i = 0; i < a.size(); i++)
    {
        a[i] -= b[i];
    }
}

int main()
{
    int n; cin >> n;
    map<char, int> integer;
    map<char, vector<int>> vec;
    for (int i = 0; i < n; i++)
    {
        string str; cin >> str;
        if (str == "int")
        {
            char x; cin >> x;
            integer[x] = 0;
            char c;
            while (true)
            {
                cin >> c;
                if (c == ';') break;
                if (c == '=') continue;
                if (c == '+')
                {
                    cin >> c;
                    if ('0' <= c && c <= '9') integer[x] += c - '0';
                    else integer[x] += integer[c];
                    continue;
                }
                if (c == '-')
                {
                    cin >> c;
                    if ('0' <= c && c <= '9') integer[x] -= c - '0';
                    else integer[x] -= integer[c];
                    continue;
                }
                if ('0' <= c && c <= '9') 
                {
                    integer[x] += c - '0';
                    continue;
                }
                if ('a' <= c && c <= 'z') 
                {
                    integer[x] += integer[c];
                    continue;
                }
            }
        }
        else if (str == "vec")
        {
            char x; cin >> x;
            char c;
            while (true)
            {
                cin >> c;
                if (c == ';') break;
                if (c == '=') continue;
                if (c == '+')
                {
                    cin >> c;
                    if ('a' <= c && c <= 'z')
                    {
                        add_vec(vec[x], vec[c]);
                        continue;
                    }
                    if (c == '[')
                    {
                        vector<int> tmp;
                        while (true)
                        {
                            cin >> c;
                            if (c == ']') break;
                            if (c == ',') continue;
                            if ('0' <= c && c <= '9') 
                            {
                                tmp.push_back(c - '0');
                                continue;
                            }
                            if ('a' <= c && c <= 'z')
                            {
                                tmp.push_back(integer[c]);
                                continue;
                            }
                        }
                        add_vec(vec[x], tmp);
                        continue;
                    }
                }
                if (c == '-')
                {
                    cin >> c;
                    if ('a' <= c && c <= 'z')
                    {
                        sub_vec(vec[x], vec[c]);
                        continue;
                    }
                    if (c == '[')
                    {
                        vector<int> tmp;
                        while (true)
                        {
                            cin >> c;
                            if (c == ']') break;
                            if (c == ',') continue;
                            if ('0' <= c && c <= '9') 
                            {
                                tmp.push_back(c - '0');
                                continue;
                            }
                            if ('a' <= c && c <= 'z')
                            {
                                tmp.push_back(integer[c]);
                                continue;
                            }
                        }
                        sub_vec(vec[x], tmp);
                        continue;
                    }
                }
                if (c == '[')
                {
                    while (true)
                    {
                        cin >> c;
                        if (c == ']') break;
                        if (c == ',') continue;
                        if ('0' <= c && c <= '9') 
                        {
                            vec[x].push_back(c - '0');
                            continue;
                        }
                        if ('a' <= c && c <= 'z')
                        {
                            vec[x].push_back(integer[c]);
                            continue;
                        }
                    }
                }
                if ('a' <= c && c <= 'z') 
                {
                    vec[x] = vec[c];
                    continue;
                }
            }
        }
        else if (str == "print_int")
        {
            int out = 0;
            char c;
            while (true)
            {
                cin >> c;
                if (c == ';') break;
                if (c == '=') continue;
                if (c == '+')
                {
                    cin >> c;
                    if ('0' <= c && c <= '9') out += c - '0';
                    else out += integer[c];
                    continue;
                }
                if (c == '-')
                {
                    cin >> c;
                    if ('0' <= c && c <= '9') out -= c - '0';
                    else out -= integer[c];
                    continue;
                }
                if ('0' <= c && c <= '9') 
                {
                    out += c - '0';
                    continue;
                }
                if ('a' <= c && c <= 'z') 
                {
                    out += integer[c];
                    continue;
                }
            }
            cout << out << endl;
        }
        else if (str == "print_vec")
        {
            vector<int> tmp;
            char c;
            while (true)
            {
                cin >> c;
                if (c == ';') break;
                if (c == '=') continue;
                if (c == '+')
                {
                    cin >> c;
                    if ('a' <= c && c <= 'z')
                    {
                        add_vec(tmp, vec[c]);
                        continue;
                    }
                    if (c == '[')
                    {
                        vector<int> tmp2;
                        while (true)
                        {
                            cin >> c;
                            if (c == ']') break;
                            if (c == ',') continue;
                            if ('0' <= c && c <= '9') 
                            {
                                tmp2.push_back(c - '0');
                                continue;
                            }
                            if ('a' <= c && c <= 'z')
                            {
                                tmp2.push_back(integer[c]);
                                continue;
                            }
                        }
                        add_vec(tmp, tmp2);
                        continue;
                    }
                }
                if (c == '-')
                {
                    cin >> c;
                    if ('a' <= c && c <= 'z')
                    {
                        sub_vec(tmp, vec[c]);
                        continue;
                    }
                    if (c == '[')
                    {
                        vector<int> tmp2;
                        while (true)
                        {
                            cin >> c;
                            if (c == ']') break;
                            if (c == ',') continue;
                            if ('0' <= c && c <= '9') 
                            {
                                tmp2.push_back(c - '0');
                                continue;
                            }
                            if ('a' <= c && c <= 'z')
                            {
                                tmp2.push_back(integer[c]);
                                continue;
                            }
                        }
                        sub_vec(tmp, tmp2);
                        continue;
                    }
                }
                if (c == '[')
                {
                    while (true)
                    {
                        cin >> c;
                        if (c == ']') break;
                        if (c == ',') continue;
                        if ('0' <= c && c <= '9') 
                        {
                            tmp.push_back(c - '0');
                            continue;
                        }
                        if ('a' <= c && c <= 'z')
                        {
                            tmp.push_back(integer[c]);
                            continue;
                        }
                    }
                }
                if ('a' <= c && c <= 'z') 
                {
                    tmp = vec[c];
                    continue;
                }
            }
            print_vec(tmp);
        }
    }
}