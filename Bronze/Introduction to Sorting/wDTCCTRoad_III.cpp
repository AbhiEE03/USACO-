// #include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  // freopen("cowqueue.in", "r", stdin);
  int N;
  cin >> N;
  vector<pair<int, int>> time(N);
  for (int i = 0; i < N; i++)
  {
    cin >> time[i].first >> time[i].second;
  }

  sort(time.begin(), time.end());
  // // Printing a vector of pair of integers
  // for (auto &i : time)
  // {
  //   cout << i.first << " " << i.second << "\n";
  // }

  int currentTime = 0;
  for (const pair<int, int> &e : time)
  {

    if (currentTime > e.first)
    {
      currentTime += e.second;
    }
    else
      currentTime = e.first + e.second;
  }

  // freopen("cowqueue.out", "w", stdout);
  cout << currentTime << endl;
}