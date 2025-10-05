#include <iostream>
#include <string>
using namespace std;

int main()
{
  string score;
  cout << "Enter the scorechart:-";
  cin >> score;

  int player1 = 0, player2 = 0;

  // Loop through the input string
  for (int i = 0; i < score.length(); i++)
  {
    char player = score[i]; // Extract 'A' or 'B'

    // Ensure we don't go out of bounds when checking the next character
    if (i + 1 < score.length() && isdigit(score[i + 1]))
    {
      int points = score[i + 1] - '0'; // Convert char digit to int
      if (player == 'A')
      {
        player1 += points;
      }
      else if (player == 'B')
      {
        player2 += points;
      }
    }
  }

  // Check winner conditions
  if (player1 >= 11 && player1 - player2 >= 2)
  {
    cout << "Player A wins with " << player1 << " points! \n"
         << endl;
  }
  else if (player2 >= 11 && player2 - player1 >= 2)
  {
    cout << "Player B wins with " << player2 << " points!" << endl;
  }
  else
  {
    cout << "No one got to 11 points." << endl;
  }

  return 0;
}