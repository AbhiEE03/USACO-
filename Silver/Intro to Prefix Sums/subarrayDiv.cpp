#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
  ll n;
  cin >> n;
  vector<ll> values(n);
  vector<ll> prefix(n + 1);
  for (int i = 0; i < n; i++)
  {
    cin >> values[i];
    prefix[i + 1] = (prefix[i] + values[i]) % n;
  }
  map<ll, ll> mpp;
  ll count = 0;
  for (auto &it : prefix)
  {
    if (it < 0)
      it += n;
    mpp[it]++;
  }

  for (auto &[re, freq] : mpp)
  {
    count += (freq * (freq - 1)) / 2;
  }
  cout << count << endl;
}