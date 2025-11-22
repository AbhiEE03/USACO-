#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
  freopen("paint.in", "r", stdin);
  freopen("paint.out", "w", stdout);
  int a, b, c, d;
  cin >> a >> b;
  cin >> c >> d;
  int interval = (b - a) + (d - c);
  int intersection = max(min(b, d) - max(a, c), 0);
  cout << interval - intersection << endl;
  return 0;
}