#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n;
vector<ll> weights;

ll minWeightDiff(int idx, ll sum1, ll sum2)
{
  if (idx == n)
    return abs(sum1 - sum2);

  return min(minWeightDiff(idx + 1, sum1 + weights[idx], sum2), minWeightDiff(idx + 1, sum1, sum2 + weights[idx]));
}

int main()
{

  cin >> n;
  weights.resize(n);
  for (int i = 0; i < n; i++)
  {
    cin >> weights[i];
  }

  cout << minWeightDiff(0, 0, 0) << endl;
}