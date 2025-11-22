#include <iostream>
#include <vector>
using namespace std;

int main()
{
  freopen("bcount.in", "r", stdin);
  freopen("bcount.out", "w", stdout);
  int n, q;
  cin >> n >> q;

  vector<int> prefix1(n + 1, 0);
  vector<int> prefix2(n + 1, 0);
  vector<int> prefix3(n + 1, 0);

  for (int i = 1; i <= n; i++)
  {
    int breed;
    cin >> breed;

    prefix1[i] = prefix1[i - 1];
    prefix2[i] = prefix2[i - 1];
    prefix3[i] = prefix3[i - 1];

    if (breed == 1)
      prefix1[i]++;
    else if (breed == 2)
      prefix2[i]++;
    else
      prefix3[i]++;
  }

  while (q--)
  {
    int l, r;
    cin >> l >> r;
    cout << prefix1[r] - prefix1[l - 1] << " "
         << prefix2[r] - prefix2[l - 1] << " "
         << prefix3[r] - prefix3[l - 1] << endl;
  }

  return 0;
}
