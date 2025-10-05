#include <bits/stdc++.h>

using namespace std;

int primeFactors(long long n)
{
  // Finding prime factors(sieve Algo)
  long long prime[n + 1];
  long long count = 0;

  for (int i = 2; i <= n; i++)
  {
    prime[i] = 1;
  }

  for (int i = 2; i * i <= n; i++)
  {
    if (prime[i] == 1)
    {
      for (int j = i * i; j <= n; j += i)
      {
        prime[j] = 0;
      }
    }
  }

  for (int i = 2; i <= n; i++)
  {
    if (prime[i] == 1 && n % i == 0)
    {
      count += 1;
    }
  }

  return count;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;

  vector<int> ans;

  while (t--)
  {
    long long a, b;
    cin >> a >> b; // a>=b
    long long n = 1;
    for (int i = (b + 1); i <= a; i++)
    {
      n *= i;
    }

    ans.push_back(primeFactors(n));
  }

  for (auto &i : ans)
    cout << i << endl;
  return 0;
}