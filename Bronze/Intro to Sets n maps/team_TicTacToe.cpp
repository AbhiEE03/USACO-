#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
#include <algorithm>

using namespace std;

void check_line(char a, char b, char c, set<char> &solo, set<string> &team)
{
  set<char> win = {a, b, c}; // unique characters in the line

  if (win.size() == 1)
  {
    solo.insert(*win.begin());
  }
  else if (win.size() == 2)
  {
    vector<char> temp(win.begin(), win.end());
    sort(temp.begin(), temp.end());
    string key = string(1, temp[0]) + temp[1];
    team.insert(key);
  }
}

int main()
{
  freopen("tttt.in", "r", stdin);

  freopen("tttt.out", "w", stdout);
  vector<vector<char>> board(3, vector<char>(3));
  for (auto &row : board)
  {
    for (auto &col : row)
    {
      cin >> col;
    }
  }

  set<char> solo;
  set<string> team;

  // Iterate through rows and columns
  for (int i = 0; i < 3; i++)
  {
    check_line(board[i][0], board[i][1], board[i][2], solo, team);
    check_line(board[0][i], board[1][i], board[2][i], solo, team);
  }

  // Iterate through diagonals
  check_line(board[0][0], board[1][1], board[2][2], solo, team);
  check_line(board[0][2], board[1][1], board[2][0], solo, team);

  cout << solo.size() << endl;
  cout << team.size() << endl;
}