#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> hierarchy(m);
  vector<pair<int, int>> order(k);
  int pos;
  for (auto &i : hierarchy)
  {
    cin >> i;
  }

  for (auto &i : order)
  {
    cin >> i.first >> i.second;
  }

  for (int i = 0; i < n; i++)
  {
    pos = i;
  }
}
// Will solvbe after greedy algo