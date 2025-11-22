#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> weights(2 * n);
  for (int i = 0; i < 2 * n; i++)
  {
    cin >> weights[i];
  }

  sort(weights.begin(), weights.end());
  int instability = INT_MAX;

  for (int i = 0; i <= 2 * n - 1; i++)
  {
    for (int j = i + 1; j <= 2 * n - 1; j++)
    {
      vector<int> remW(2 * n - 2);
      for (int k = 0; k <= 2 * n - 1; k++)
      {
        if (k != i && k != j)
          remW.push_back(weights[k]);
      }

      int left = 0, temp = 0;
      while (left < remW.size() - 1)
      {
        temp += abs(remW[left + 1] - remW[left]);
        // instability = min(temp, abs(remW[left + 1] - remW[left]));
        left += 2;
      }

      instability = min(temp, instability);
    }
  }

  cout << instability << "\n";
}