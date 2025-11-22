#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long n, x;
  cin >> n >> x;
  map<long long, long long> mpp;
  mpp[0] = 1;
  vector<long long> values(n);
  long long preSum = 0;
  long long count = 0;
  for (long long i = 0; i < n; i++)
  {
    cin >> values[i];
    preSum += values[i];
    long long remove = preSum - x;
    count += mpp[remove];
    mpp[preSum]++;
  }

  cout << count << endl;
}