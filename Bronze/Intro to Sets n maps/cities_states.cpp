#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdio>

using namespace std;

int main()
{
  freopen("citystate.in", "r", stdin);
  freopen("citystate.out", "w", stdout);
  int n;
  cin >> n;
  vector<pair<string, string>> names;
  for (int i = 0; i < n; i++)
  {

    string f;
    string code;
    cin >> f >> code;
    string city = f.substr(0, 2);
    names.push_back({city, code});
  }

  unordered_map<string, int> seen;
  long long total = 0;
  for (const auto &[c, s] : names)
  {
    if (c != s)
    {
      total += seen[s + c];
    }
    seen[c + s]++;
  }

  cout << total << endl;
}