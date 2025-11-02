#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<pair<string, string>> restrictions;

  for (int i = 0; i < n; i++)
  {
    string a, t, b;
    cin >> a;
    cin >> t >> t >> t >> t;
    cin >> b;
    restrictions.push_back({a, b});
  }

  vector<string> cows = {"Bessie", "Buttercup", "Belinda", "Beatrice",
                         "Bella", "Blue", "Betsy", "Sue"};
  sort(cows.begin(), cows.end());
  int count = 0;

  while (next_permutation(cows.begin(), cows.end()))
  {
    bool passed = true;
    for (auto p : restrictions)
    {
      string cow1 = p.first;
      string cow2 = p.second;
      auto a = find(cows.begin(), cows.end(), cow1);
      auto b = find(cows.begin(), cows.end(), cow2);
      if (abs(a - b) != 1)
      {
        passed = false;
      }
    }
    if (passed)
    {
      break;
    }
  }

  for (auto cow : cows)
  {
    cout << cow << endl;
  }
}