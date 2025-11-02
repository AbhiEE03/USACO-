#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<int> x(N);
  vector<int> y(N);

  for (int &i : x)
  {
    cin >> i;
  }

  for (int &i : y)
  {
    cin >> i;
  }

  long maxDistance = 0;

  for (int i = 0; i < N; i++)
  {
    for (int j = i + 1; j < N; j++)
    {
      long temp = pow((x[j] - x[i]), 2) + pow((y[j] - y[i]), 2);
      maxDistance = max(maxDistance, temp);
    }
  }

  cout << maxDistance << endl;
}