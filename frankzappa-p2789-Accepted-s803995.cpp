#include <iostream>
#include <string>

using namespace std;

int * numbers(string s) {
  int * nums = new int[3]();
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1')
      nums[0]++;
    if (s[i] == '2')
      nums[1]++;
    if (s[i] == '3')
      nums[2]++;
  }
  return nums;
}

int main() {
  string s;
  cin >> s;
  int * nums = numbers(s);
  s = "";
  while(nums[0] + nums[1] + nums[2] > 1)
      if (nums[0] > 0) {
	    s += "1+";
	    nums[0]--;
	  }
      else if (nums[1] > 0) {
	    s += "2+";
	    nums[1]--;
	  }
      else if (nums[2] > 0) {
	    s += "3+";
	    nums[2]--;
	  }
  if (nums[0] == 1)
    s += "1";
  if (nums[1] == 1)
    s += "2";
  if (nums[2] == 1)
    s += "3";
  cout << s << endl;
}
