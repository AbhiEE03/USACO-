#include <iostream>
#include <vector>

using namespace std;
int main()
{
  int n;
  cin >> n;
  int problems = 0;
  while (n--)
  {
    int x, y, z;
    cin >> x >> y >> z;
    int sum = x + y + z;
    if (sum >= 2)
      problems++;
  }

  cout << problems << endl;
}