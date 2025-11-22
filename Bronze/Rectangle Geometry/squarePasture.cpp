#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
  freopen("square.in", "r", stdin);
  freopen("square.out", "w", stdout);
  int a1, b1, c1, d1;
  int a2, b2, c2, d2;
  cin >> a1 >> b1 >> c1 >> d1 >> a2 >> b2 >> c2 >> d2;
  int x1 = min(a1, a2);
  int x2 = max(c1, c2);
  int y1 = min(b1, b2);
  int y2 = max(d1, d2);
  int side = max(x2 - x1, y2 - y1);
  cout << side * side << endl;
}