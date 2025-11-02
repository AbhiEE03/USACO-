#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
  freopen("notlast.in", "r", stdin);
  freopen("notlast.out", "w", stdout);
  int total = 7;
  int n;
  cin >> n;
  map<string, int> log;

  for (int i = 0; i < n; i++)
  {
    string name;
    int milk;
    cin >> name >> milk;
    log[name] += milk;
  }

  vector<pair<int, string>> cows;
  for (pair<string, int> it : log)
  {
    cows.push_back({it.second, it.first});
  }
  sort(cows.begin(), cows.end());

  int idx = 0;
  if (cows.size() == total)
  {
    while (idx < total && (cows[idx].first == cows[0].first))
    {
      idx++;
    }
  }

  if (idx < cows.size() &&
      (idx + 1 == cows.size() || cows[idx].first != cows[idx + 1].first))
  {
    cout << cows[idx].second << endl;
  }
  else
  {
    cout << "Tie" << endl;
  }
}