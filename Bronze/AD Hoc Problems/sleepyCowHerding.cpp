#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("herding.in", "r", stdin);
  freopen("herding.out", "w", stdout);

  vector<int> pos(3);
  for (auto &i : pos)
  {
    cin >> i;
  }
  sort(pos.begin(), pos.end());

  if (pos[2] - pos[0] == 2)
  {
    cout << '0' << endl;
  }
  else if (pos[0] == pos[1] - 2 || pos[1] == pos[2] - 2)
  {
    cout << "1" << endl;
  }
  else
  {
    cout << '2' << endl;
  }

  cout << max(pos[2] - pos[1], pos[1] - pos[0]) - 1 << endl;
}