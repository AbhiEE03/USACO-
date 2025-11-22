#include <iostream>
#include <algorithm>
using namespace std;

int area(int a, int b, int c, int d)
{
  return ((c - a) * (d - b));
}

int main()
{
  // freopen("billboard.in", "r", stdin);
  // freopen("billboard.out", "w", stdout);
  int a1, b1, c1, d1;
  int a2, b2, c2, d2;
  int a3, b3, c3, d3;
  cin >> a1 >> b1 >> c1 >> d1 >> a2 >> b2 >> c2 >> d2 >> a3 >> b3 >> c3 >> d3;
  int area1 = area(a1, b1, c1, d1);
  int area2 = area(a2, b2, c2, d2);

  //  Intersection //
  int xOverlap1 = max(0, (min(c1, c3) - max(a1, a3)));
  int xOverlap2 = max(0, (min(c2, c3) - max(a2, a3)));
  int yOverlap1 = max(0, (min(d1, d3) - max(b1, b3)));
  int yOverlap2 = max(0, (min(d2, d3) - max(b2, b3)));

  int intersection1 = xOverlap1 * yOverlap1;
  int intersection2 = xOverlap2 * yOverlap2;

  cout << (area1 + area2) - (intersection1 + intersection2) << endl;
}
