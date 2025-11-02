#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;

  int count = 0;
  vector<int> size(n);
  for (int i = 0; i < n; i++)
  {
    cin >> size[i];
  }

  sort(size.begin(), size.end());

  // Printing the sorted array
  // for (int i = 0; i < n; i++)
  // {
  //   cout << size[i] << " ";
  // }

  for (int i = 0; i < n; i++)
  {
    if (size[i] - size[0] <= k)
      count++;
    else
      continue;
  }

  cout << count << endl;
  return 0;
}