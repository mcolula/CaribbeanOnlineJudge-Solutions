#include <iostream>
#include <iterator>
#include <sstream>
#include <istream>
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<string> split(string s) {
  istringstream buffer(s);
  istream_iterator<string> beg(buffer), end;
  vector<string> words(beg, end);	
  return words;
}

int main () {
  set<string> sounds;
  vector<string> rec;
  int t;
  string l;
  string s;
  cin >> t;
  while (t--) {
	cin.ignore(256, '\n');
    cin.clear();	
    getline(cin, l);
    while(cin >> s >> s >> s && s != "the") 
      sounds.insert(s);
    rec = split(l);	
    for (auto &i: rec)
      if (sounds.find(i) == sounds.end())
        cout << i << " ";
    cout << endl;
    
  } 
  return 0;
}
