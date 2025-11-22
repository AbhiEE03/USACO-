#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
  long long n, q;
  cin >> n >> q;
  vector<long long> values(n);
  vector<long long> sum(n + 1, 0);
  vector<long long> ans;
  for (auto &it : values)
    cin >> it;

  for (long long i = 0; i < n; i++)
    sum[i + 1] = sum[i] + values[i];
  while (q--)
  {
    long long l, r;
    cin >> l >> r;
    ans.push_back(sum[r] - sum[l]);
  }
  for (auto it : ans)
    cout << it << endl;
  return 0;
}