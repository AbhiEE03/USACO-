#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
// Incomplete /////
int main()
{
  int k, n;
  cin >> k >> n;
  vector<int> judges(k);
  vector<int> polycarp(n);
  for (auto &it : judges)
    cin >> it;
  for (auto &it : polycarp)
    cin >> it;

  int initial_score = 0, sum = 0, final = 0, preSum = 0;
  unordered_set<int> initial;
  for (auto it : judges)
  {
    sum += it;
  }

  for (int i = 0; i < k; i++)
  {
    preSum += judges[i];
    for (auto it : polycarp)
    {
      final = 0;
      initial_score = it - preSum;
      final = initial_score + sum;
      if (final <= 4000000)
      {
        initial.insert(initial_score);
      }
      else
        continue;
    }
  }

  if (initial.size() == 0)
  {
    cout << "0" << endl;
  }
  else
    cout << initial.size() << endl;
}
