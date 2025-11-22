#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n, x;
  cin >> n >> x;
  vector<pair<int, int>> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i].first;
    arr[i].second = i;
  }

  sort(arr.begin(), arr.end());

  bool found = false;

  for (int l = 0; l < n - 2 && !found; l++)
  {
    if (l > 0 && arr[l].first == arr[l - 1].first)
      continue;

    int r = n - 1, sum;
    int m = l + 1;
    while (m < r)
    {
      sum = arr[l].first + arr[r].first + arr[m].first;
      if (sum == x)
      {
        found = true;
        cout << arr[l].second + 1 << " " << arr[m].second + 1 << " " << arr[r].second + 1 << " " << endl;
        break;
      }
      sum > x ? r-- : m++;
    }
  }

  if (!found)
  {
    cout << "IMPOSSIBLE";
  }
}