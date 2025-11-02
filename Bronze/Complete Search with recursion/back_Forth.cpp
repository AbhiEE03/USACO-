#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

set<int> readings;
void milkQuantity(int a, int n, vector<int> &bucketsA, vector<int> &bucketsB)
{

  if (n == 4)
  {
    readings.insert(a);
    return;
  }

  if (n % 2 == 0) // Even turn: transfer A → B
  {
    for (int i = bucketsA.size() - 1; i >= 0; i--)
    {
      if (i + 1 < bucketsA.size() && bucketsA[i] == bucketsA[i + 1])
        continue;

      int val = bucketsA[i];
      int tempA = a - val;

      bucketsA.erase(bucketsA.begin() + i);
      bucketsB.push_back(val);
      milkQuantity(tempA, n + 1, bucketsA, bucketsB);
      bucketsB.pop_back();
      bucketsA.insert(bucketsA.begin() + i, val);
    }
  }
  else // Odd turn: transfer B → A
  {
    for (int i = bucketsB.size() - 1; i >= 0; i--)
    {
      if (i + 1 < bucketsB.size() && bucketsB[i] == bucketsB[i + 1])
        continue;

      int val = bucketsB[i];
      int tempA = a + val;

      bucketsB.erase(bucketsB.begin() + i);
      bucketsA.push_back(val);
      milkQuantity(tempA, n + 1, bucketsA, bucketsB);
      bucketsA.pop_back();
      bucketsB.insert(bucketsB.begin() + i, val);
    }
  }
}

int main()
{

  int a = 1000, b = 1000;
  vector<int> bucketsA(10);
  vector<int> bucketsB(10);

  for (auto &i : bucketsA)
  {
    cin >> i;
  }
  for (auto &i : bucketsB)
  {
    cin >> i;
  }
  sort(bucketsA.begin(), bucketsA.end());
  sort(bucketsB.begin(), bucketsB.end());
  // //Printing output
  // for (auto i : bucketsA)
  // {
  //   cout << i << endl;
  // }

  milkQuantity(a, 0, bucketsA, bucketsB);
  cout << readings.size();
}