/*
Keep track of odd and even breeds and keep odds<even and even=odd+1.
2 odds make an even
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, even = 0, odd = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int breed;
    cin >> breed;
    if (breed % 2 == 0)
      even++;
    else
      odd++;
  }

  while (odd > even)
  {
    odd -= 2;
    even++;
  }

  if (even > odd + 1)
    even = odd + 1;

  cout << odd + even << endl;
}