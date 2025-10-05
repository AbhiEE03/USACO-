#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
  vector<int> nums(7);
  for (int i = 0; i < 7; i++)
  {
    cin >> nums[i];
  }

  sort(nums.begin(), nums.end());
  int a = nums[0], b = nums[1];
  int c = nums[6] - (a + b);
  cout << a << " " << b << " " << c << endl;
}