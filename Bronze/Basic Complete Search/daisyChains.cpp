#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> petals(n);

  for (int &i : petals)
  {
    cin >> i;
  }

  int valid_Photos = n;

  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      double avg_Petals = 0;

      for (int p = i; p <= j; p++)
      {
        avg_Petals += petals[p];
      }
      avg_Petals /= j - i + 1;

      for (int idx = i; idx <= j; idx++)
      {
        if (petals[idx] == avg_Petals)
        {
          valid_Photos++;
          break;
        }
      }
    }
  }

  cout << valid_Photos << endl;
}