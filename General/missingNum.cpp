/*
You are given all numbers between 1,2,\ldots,n except one. Your task is to find the missing number.
Input
The first input line contains an integer n.
The second line contains n-1 numbers. Each number is distinct and between 1 and n (inclusive).
Output
Print the missing number.
Constraints

2 \le n \le 2 \cdot 10^5

Example
Input:
5
2 3 1 5

Output:
4*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
  long long n;
  cin >> n;

  long long expSum = (n * (n + 1)) / 2;
  long long actualSum = 0;

  // Dynamic memory allocation (needs to be deleted)
  long long *list = new long long[n - 1];
  for (int i = 0; i < n - 1; i++)
  {
    cin >> list[i];
    actualSum += list[i];
  }

  // cout << actualSum << "  " << expSum << endl;
  long long missingNum = expSum - actualSum;
  cout << missingNum;
  return 0;
}