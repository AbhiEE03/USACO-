#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

int main()
{
  // ifstream fin("citystate.in");
  // ofstream fout("citystate.out");

  int N;
  cin >> N;

  map<pair<string, string>, int> freq;
  long long total = 0;

  for (int i = 0; i < N; i++)
  {
    string city, state;
    cin >> city >> state;
    string prefix = city.substr(0, 2);

    if (prefix != state)
    {
      // Look for reverse pair (state, prefix)
      total += freq[{state, prefix}];
    }

    // Record the current pair
    freq[{prefix, state}]++;
  }

  cout << total << endl;
  return 0;
}
