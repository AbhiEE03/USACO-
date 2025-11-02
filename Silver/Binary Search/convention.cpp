#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool can_Assign(vector<ll> &time, ll cows, ll capacity, ll buses, ll x)
{
  ll usedBuses = 1, firstCow = time[0], countInBus = 1;
  for (ll i = 1; i < cows; i++)
  {
    if ((time[i] - firstCow) > x || countInBus == capacity)
    {
      usedBuses++;
      firstCow = time[i];
      countInBus = 1;
    }
    else
    {
      countInBus++;
    }
  }
  return usedBuses <= buses;
}

int main()
{
  freopen("convention.in", "r", stdin);
  freopen("convention.out", "w", stdout);

  ll cows,
      buses, capacity;
  cin >> cows >> buses >> capacity;
  vector<ll> time(cows);

  for (auto &it : time)
    cin >> it;

  sort(time.begin(), time.end());

  ll low = 0, high = time[cows - 1] - time[0];
  while (low <= high)
  {
    ll mid = low + (high - low) / 2;
    if (can_Assign(time, cows, capacity, buses, mid))
    {
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  cout << low << endl;
}
/* Inefficient logic
We can take each bus with max capacity as many times as possible and if in the end
there aren't enough cows to fill the buses we will take partially filled bus.
Max waiting time will be the difference between the first and last cow
to enter int a bus
*/

// ll extra = (buses * capacity) - cows;
// for (ll i = 0; (i + capacity - 1) < cows; i += capacity)
// {
//   waiting_Time = max(waiting_Time, time[i + capacity - 1] - time[i]);
// }

// waiting_Time = max(waiting_Time, time[cows - 1] - time[cows - extra]);

// cout << waiting_Time << endl;
/*
Farmer John is hosting a new bovine grass-eating convention at his farm!
Cows from all over the world are arriving at the local airport to attend the convention and eat grass. Specifically, there are N
 cows arriving at the airport (1≤N≤105
) and cow i
 arrives at time ti
 (0≤ti≤109
). Farmer John has arranged M
 (1≤M≤105
) buses to transport the cows from the airport. Each bus can hold up to C
 cows in it (1≤C≤N
). Farmer John is waiting with the buses at the airport and would like to assign the arriving cows to the buses. A bus can leave at the time when the last cow on it arrives. Farmer John wants to be a good host and so does not want to keep the arriving cows waiting at the airport too long. What is the smallest possible value of the maximum waiting time of any one arriving cow if Farmer John coordinates his buses optimally? A cow’s waiting time is the difference between her arrival time and the departure of her assigned bus.

It is guaranteed that MC≥N
.

INPUT FORMAT (file convention.in):
The first line contains three space separated integers N
, M
, and C
. The next line contains N
 space separated integers representing the arrival time of each cow.
OUTPUT FORMAT (file convention.out):
Please write one line containing the optimal minimum maximum waiting time for any one arriving cow.
SAMPLE INPUT:
6 3 2
1 1 10 14 4 3
SAMPLE OUTPUT:
4
If the two cows arriving at time 1 go in one bus, cows arriving at times 3 and 4 in the second,
and cows arriving at times 10 and 14 in the third, the longest time a cow has to wait is 4 time
 units (the cow arriving at time 10 waits from time 10 to time 14).
*/
