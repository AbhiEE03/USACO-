#include <iostream>
#include <vector>

using namespace std;

int main()
{
  for (int i = 0; i < 11; i++)
  {
    cout << i % 3 << " ";
    cout << (i + 1) % 3 << endl;
  }
}
