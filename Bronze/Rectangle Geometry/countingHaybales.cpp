#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  freopen("haybales.in", "r", stdin);
  freopen("haybales.out", "w", stdout);
  int n, q;
  cin >> n >> q;
  vector<int> loc(n);
  for (int i = 0; i < n; i++)
    cin >> loc[i];

  sort(loc.begin(), loc.end());
  for (int i = 0; i < q; i++)
  {
    int a, b;
    cin >> a >> b;
    cout << upper_bound(loc.begin(), loc.end(), b) - lower_bound(loc.begin(), loc.end(), a) << endl;
  }
}