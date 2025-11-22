#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
  freopen("div7.in", "r", stdin);
  freopen("div7.out", "w", stdout);
  ll n;
  cin >> n;
  vector<ll> id(n);
  vector<ll> prefix(n + 1);
  for (int i = 0; i < n; i++)
  {
    cin >> id[i];
    prefix[i + 1] = (prefix[i] + id[i]) % 7;
  }

  int maximum = 0;
  vector<int> lastFound(7, -1);
  for (int i = 0; i < prefix.size(); i++)
  {
    if (lastFound[prefix[i]] == -1)
      lastFound[prefix[i]] = i;
    else
      maximum = max(maximum, i - lastFound[prefix[i]]);
  }

  cout << maximum << endl;
}