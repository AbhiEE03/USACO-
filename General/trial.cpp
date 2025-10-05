#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 5;
vector<int> primes;

// Sieve to generate primes up to MAX
void generatePrimes()
{
  vector<bool> isPrime(MAX, true);
  isPrime[0] = isPrime[1] = false;

  for (int i = 2; i < MAX; ++i)
  {
    if (isPrime[i])
    {
      primes.push_back(i);
      for (int j = 2 * i; j < MAX; j += i)
        isPrime[j] = false;
    }
  }
}

// Count distinct prime factors of product of (b+1) to a
int countDistinctPrimeFactors(int a, int b)
{
  unordered_set<int> distinctFactors;

  for (int i = b + 1; i <= a; ++i)
  {
    int x = i;
    for (int p : primes)
    {
      if (p * p > x)
        break;
      if (x % p == 0)
      {
        distinctFactors.insert(p);
        while (x % p == 0)
          x /= p;
      }
    }
    if (x > 1)
      distinctFactors.insert(x); // x is prime
  }

  return distinctFactors.size();
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  generatePrimes(); // Precompute primes

  int t;
  cin >> t;
  vector<int> ans;

  while (t--)
  {
    int a, b;
    cin >> a >> b;
    ans.push_back(countDistinctPrimeFactors(a, b));
  }

  for (int res : ans)
    cout << res << "\n";

  return 0;
}
