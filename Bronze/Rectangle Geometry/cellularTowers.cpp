#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> cities, towers;

  for (int i = 0; i < n; i++)
  {
    int city;
    cin >> city;
    cities.push_back(city);
  }

  for (int i = 0; i < m; i++)
  {
    int tower;
    cin >> tower;
    towers.push_back(tower);
  }

  int min_r = 0;
  for (int i = 0; i < n; i++)
  {
    int tower_right =
        lower_bound(begin(towers), end(towers), cities[i]) - begin(towers);
    int tower_left = tower_right - 1;

    int min_r_for_this_city = INT_MAX;
    if (tower_right < m)
    {
      assert(towers[tower_right] >= cities[i]);
      min_r_for_this_city =
          min(min_r_for_this_city, towers[tower_right] - cities[i]);
    }
    if (tower_left >= 0)
    {
      assert(towers[tower_left] <= cities[i]);
      min_r_for_this_city =
          min(min_r_for_this_city, cities[i] - towers[tower_left]);
    }

    min_r = max(min_r, min_r_for_this_city);
  }

  cout << min_r << endl;
}
