#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<pair<int, char>> loc;

  for (int i = 0; i < n; i++)
  {
    int p;
    char c;
    cin >> c >> p;
    loc.push_back({p, c});
  }
  sort(loc.begin(), loc.end());

  int minLiars = n;

  for (int i = 0; i < n; i++)
  {
    int numLiars = 0;
    for (int j = 0; j < i; j++)
    {
      if (loc[j].second == 'L')
        numLiars++;
    }

    for (int j = i + 1; j < n; j++)
    {
      if (loc[j].second == 'G')
        numLiars++;
    }
    minLiars = min(minLiars, numLiars);
  }

  cout << minLiars << endl;
}