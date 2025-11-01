/*
Assign the first day in lastDay and take the subscription for day-1
For each coming day u have 2 optioons either u take a new subscription or extend
the previous one which will be decided by which one is cheaper : d - lastDay < k + 1
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long;

int main()
{
  ll n, k;
  cin >> n >> k;
  vector<ll> days(n);
  for (auto &it : days)
    cin >> it;

  ll lastDay = days[0];
  ll cost = k + 1;

  for (int i = 1; i < n; i++)
  {
    if (days[i] - lastDay < k + 1)
      cost += days[i] - lastDay;
    else
      cost += k + 1;

    lastDay = days[i];
  }

  cout << cost << endl;
}