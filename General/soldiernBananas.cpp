#include <iostream>
using namespace std;

int main()
{
  int k, n, w;
  cin >> k >> n >> w;
  int req = 0, i = 1;
  while (w--)
  {
    req += (i * k);
    i++;
  }
  if (req > n)
    cout << req - n << endl;
  else
    cout << "0" << endl;
}