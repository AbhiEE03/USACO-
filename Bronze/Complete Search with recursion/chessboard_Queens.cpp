#include <bits/stdc++.h>

using namespace std;

bool isSafe(vector<string> &board, int row, int col, int n)
{
  // check vertical (same column)
  for (int i = 0; i < row; i++)
  {
    if (board[i][col] == 'Q')
      return false;
  }

  // check left diagonal
  for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
  {
    if (board[i][j] == 'Q')
      return false;
  }

  // check right diagonal
  for (int i = row, j = col; i >= 0 && j < n; i--, j++)
  {
    if (board[i][j] == 'Q')
      return false;
  }

  return true;
}
int nQueens(int n, vector<string> &board, int row)
{
  int placed = 0;
  if (row == n)
  {
    return 1;
  }

  for (int i = 0; i < n; i++)
  {
    if (isSafe(board, row, i, n) && !(board[row][i] == '*'))
    {
      board[row][i] = 'Q';
      placed += nQueens(n, board, row + 1);
      board[row][i] = '.';
    }
  }
  return placed;
}

int main()
{
  int n = 8;

  vector<string> board(8);
  for (int i = 0; i < 8; i++)
    cin >> board[i];
  int totalValidPlacement = nQueens(n, board, 0);
  cout << totalValidPlacement << endl;
}