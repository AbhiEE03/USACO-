#include <iostream>
#include <string>
using namespace std;
int main()
{
  freopen("breedflip.in", "r", stdin);
  freopen("breedflip.out", "w", stdout);
  int n;
  cin >> n;
  string a;
  string b;

  cin >> a >> b;
  int ops = 0;
  bool found = false;
  for (int i = 0; i < n; i++)
  {
    if (a[i] != b[i])
    {
      if (!found)
      {
        found = true;
        ops++;
      }
    }
    else
      found = false;
    ;
    }
  cout << ops << endl;
}