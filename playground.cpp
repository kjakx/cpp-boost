#include <bits/stdc++.h>
using namespace std;

int min_problems(vector<bool>, int, int, int);
int d, g;
int max_problems;
vector<int> p;
vector<int> bonus;

int main()
{
    cin >> d >> g;
    p.resize(d+1, 0);
    bonus.resize(d+1, 0);
    vector<bool> solved(d+1, false);
    max_problems = 0;
    for (int i = 1; i <= d; i++)
    {
        cin >> p[i] >> bonus[i];
        max_problems += p[i];
    }
    int problems = max_problems;
    for (int i = 0; i <= d; i++)
    {
        problems = min(problems, min_problems(solved, i, 0, 0));
    }
    cout << problems << endl;
    return 0;
}

int min_problems(vector<bool> solved, int pid, int score, int problems)
{
    int problems_goal = max_problems;
    score += p[pid] * pid * 100 + bonus[pid];
    problems += p[pid];
    solved[pid] = true;
    if (score < g)
    {
        int max_unsolved_pid = 0;
        for (int i = d; i >= 1; i--)
        {
            if (solved[i] == false)
            {
                max_unsolved_pid = i;
                break;
            }
        }
        for (int i = 1; i < p[max_unsolved_pid]; i++)
        {
            if (score + i * max_unsolved_pid * 100 >= g)
            {
                score += i * max_unsolved_pid * 100;
                problems += i;
                problems_goal = problems;
                break;
            }
        }
    }
    else problems_goal = problems;
    if (score < g)
    {
        for (int i = pid+1; i <= d; i++)
        {
            problems_goal = min(problems_goal, min_problems(solved, i, score, problems));
        }
    }
    return problems_goal;
}