#include <bits/stdc++.h>
using namespace std;
int main()
{
  freopen("maxcross.in", "r", stdin);
  freopen("maxcross.out", "w", stdout);

  int n, k, b;
  cin >> n >> k >> b;

  vector<int> signal(n, 0);
  for (int i = 0; i < b; i++)
  {
    int damage;
    cin >> damage;

    signal[damage - 1] = 1;
  }

  int broken = 0;
  for (int i = 0; i < k; i++)
  {
    if (signal[i])
      broken++;
  }

  int result = broken;
  int l = 0, r = k, repair = 0;
  for (; r < n; r++)
  {
    if (signal[r] == 1)
      broken++;
    if (signal[l] == 1)
    {
      broken--;
      l++;
    }
    else
      l++;

    result = min(result, broken);
  }

  cout << result << endl;
}