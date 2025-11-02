#include <bits/stdc++.h>
using namespace std;

int main()
{
  int K, N;
  cin >> K >> N;

  vector<vector<int>> sessions(K, vector<int>(N));
  // Read K sessions
  for (int i = 0; i < K; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> sessions[i][j];
      sessions[i][j]--; // convert to 0-indexed
    }
  }

  // Precompute rankings: rank[s][cow] = position of cow in session s
  vector<vector<int>> rank(K, vector<int>(N));
  for (int s = 0; s < K; s++)
  {
    for (int pos = 0; pos < N; pos++)
    {
      int cow = sessions[s][pos];
      rank[s][cow] = pos;
    }
  }

  int consistent_pairs = 0;

  // Check all pairs (a, b)
  for (int a = 0; a < N; a++)
  {
    for (int b = 0; b < N; b++)
    {
      if (a == b)
        continue;

      bool a_better = true;
      for (int s = 0; s < K; s++)
      {
        if (rank[s][a] >= rank[s][b])
        {
          a_better = false;
          break;
        }
      }

      if (a_better)
        consistent_pairs++;
    }
  }

  cout << consistent_pairs << endl;
  return 0;
}