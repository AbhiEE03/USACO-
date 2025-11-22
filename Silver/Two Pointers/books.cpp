#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n, t;
  cin >> n >> t;

  vector<int> a(n);
  for (auto &i : a)
    cin >> i;

  int books = 0, curr = 0;
  int l = 0, r = 0;
  for (; r < n; r++)
  {
    curr += a[r];

    while (curr > t)
    {
      curr -= a[l];
      l++;
    }
    books = max(books, r - l + 1);
  }

  cout << books << endl;
}