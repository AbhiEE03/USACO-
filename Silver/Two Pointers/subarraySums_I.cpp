#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n, x;
  cin >> n >> x;
  vector<int> arr(n);

  for (auto &i : arr)
    cin >> i;
  int count = 0, l = 0, r = 0, preSum = 0, result;
  for (; r < n; r++)
  {
    preSum += arr[r];
    while (preSum > x && left <= right)
    {
      preSum -= arr[l];
      l++;
    }

    if (preSum == x)
      count++;
  }
  cout << count << endl;
}
