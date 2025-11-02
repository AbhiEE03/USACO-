#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, X;
  cin >> N >> X;

  vector<int> a(N);
  for (int &i : a)
  {
    cin >> i;
  }

  sort(a.begin(), a.end());
  int count = 0;

  while (X > 0)
  {
    for (int i : a)
    {

      X -= i;
      if (X <= 0)
        break;
      count++;
    }
  }

  cout << count << endl;
}
