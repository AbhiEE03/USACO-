#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//  Method 1 //
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

  int l = 0, r = n - 1, sum;
  bool found = false;
  while (l < r)
  {
    sum = arr[l].first + arr[r].first;
    if (sum == x)
    {
      found = true;
      cout << arr[l].second + 1 << " " << arr[r].second + 1;
      break;
    }
    else if (sum > x)
      r--;
    else
      l++;
  }

  if (!found)
  {
    cout << "IMPOSSIBLE";
  }
}