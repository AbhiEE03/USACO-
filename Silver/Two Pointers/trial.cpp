#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, t;
  cin >> n >> t;

  vector<int> a(n);
  for (auto &i : a)
    cin >> i;

  int l = 0, r = 0, curr = 0, ans = 0;

  for (; r < n; r++)
  {
    curr += a[r];
    if (curr > t)
    {
      curr -= a[l];
      l++;
    }

    ans = max(ans, r - l + 1);
  }

  cout << ans << endl;
}