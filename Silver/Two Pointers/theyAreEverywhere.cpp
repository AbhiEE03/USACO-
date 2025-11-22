#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<char> s(n);
  unordered_map<char, int> pokemon;
  for (int i = 0; i < n; i++)
  {
    cin >> s[i];
    pokemon[s[i]]++;
  }

  int uniq = pokemon.size();
  pokemon.clear();
  int flats = n;

  for (int i = 0, j = 0; i < n; i++)
  {
    while (j < n && pokemon.size() < uniq)
      pokemon[s[j++]]++;
    if (pokemon.size() == uniq)
      flats = min(flats, j - i);
    if (!--pokemon[s[i]])
      pokemon.erase(s[i]);
  }
  cout << flats << endl;
}