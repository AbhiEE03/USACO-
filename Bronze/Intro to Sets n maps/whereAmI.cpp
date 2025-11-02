#include <iostream>
#include <string>
#include <unordered_map>
#include <cstdio>

using namespace std;

int main()
{
  freopen("whereami.in", "r", stdin);
  freopen("whereami.out", "w", stdout);
  int n;
  cin >> n;
  string color;
  cin >> color;
  unordered_map<string, int> freq;

  for (int len = 1; len < n; len++)
  {
    bool sol = true;
    for (int idx = 0; idx <= n - len; idx++)
    {
      string sub = color.substr(idx, len);
      freq[sub]++;
      if (freq[sub] > 1)
        sol = false;
    }
    if (sol)
    {
      cout << len << endl;
      break;
    }
  }
}