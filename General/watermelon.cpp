#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;

  int a = n - 2;
  if (a > 0 && a % 2 == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
