#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a)
  {
    cin >> i;
  }

  int numSwaps = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n - 1; j++)
    {
      if (a[j] > a[j + 1])
      {
        swap(a[j], a[j + 1]);
        numSwaps++;
      }
    }
  }

  // Printing the sorted Vector
  //  for (int i : a)
  //  {
  //    cout << i << " ";
  //  }

  cout << "Array is sorted in " << numSwaps << " swaps." << endl;
  cout << "First Element: " << a[0] << endl;
  cout << "Last Element: " << a[n - 1] << endl;
}