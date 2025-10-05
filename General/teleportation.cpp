#include <iostream>
#include <algorithm>
using namespace std;

int minHaul(int a, int b, int x, int y)
{
  int operations = 0;
  int dx = abs(a - x);
  int dy = abs(a - y);
  if (dx >= dy)
  {
    operations += dy;
    operations += abs(b - x);
  }

  if (dx < dy)
  {
    operations += dx;
    operations += abs(b - y);
  }

  int hauling = abs(a - b);
  return min(hauling, operations);
}
int main()
{
  freopen("teleport.in", "r", stdin);
  freopen("teleport.out", "w", stdout);
  int a, b, x, y;
  cin >> a >> b >> x >> y;
  cout << minHaul(a, b, x, y);
  return 0;
}