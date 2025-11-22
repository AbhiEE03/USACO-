#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
  ll n;
  cin >> n;
  vector<ll> arr(n);
  ll preSum = 0, sum = INT_MIN;
  for (auto &it : arr)
  {
    cin >> it;
    preSum += it;
    sum = max(sum, preSum);
    if (preSum < 0)
      preSum = 0;
  }
  cout << sum << endl;
}