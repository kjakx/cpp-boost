#include <bits/stdc++.h>
using namespace std;

int main() {
  char c[4];
  for (int i = 0; i < 4; i++)
  {
      cin >> c[i];
  }
  if ((c[0] == c[1] && c[1] == c[2]) || (c[1] == c[2] && c[2] == c[3]))
    cout << "Yes" << endl;
  else cout << "No" << endl;
}