#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ll machines, products;
  cin >> machines >> products;
  vector<ll> time(machines);
  for (auto &it : time)
  {
    cin >> it;
  }
  sort(time.begin(), time.end());
  ll currTime = 0;

  /*
  machines are working simultaneously so we don't need
  to wait for one to finish before we start the next
  */

  ll low = 0, high = time[0] * products;
  while (low <= high)
  {
    ll mid = low + (high - low) / 2;
    ll made = 0;
    for (ll i = 0; i < machines; i++)
    {
      made += (mid / time[i]);
      if (made >= products)
        break;
    }

    if (made >= products)
    {
      currTime = mid;
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }

  cout << currTime << endl;
}

/*
////////QUESTION/////////
A factory has n machines which can be used to make products. Your goal is to make a total of t
 products.
For each machine, you know the number of seconds it needs to make a single product.
The machines can work simultaneously, and you can freely decide their schedule.
What is the shortest time needed to make t products?
Input
The first input line has two integers n and t: the number of machines and products.
The next line has n integers k_1,k_2,\dots,k_n: the time needed to make a product using each machine.
Output
Print one integer: the minimum time needed to make t products.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le t \le 10^9
1 \le k_i \le 10^9

Example
Input:
3 7
3 2 5

Output:
8

Explanation: Machine 1 makes two products,
 machine 2 makes four products and machine 3 makes one product.
*/

/*INCORRECT LOGIC*/
// for (auto &it : time)
// {
//   made += products / it;
//   ll rem = products - made;
//   if (rem >= 0)
//   {
//     currTime += it;
//   }
//   else
//   {
//     currTime -= (abs(rem) * it);
//     break;
//   }
// }
// cout << currTime << endl;