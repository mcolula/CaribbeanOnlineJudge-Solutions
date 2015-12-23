#include <algorithm>
#include <iostream>
#include <string>	


using namespace std;

int word_count(string word, string text) {
  if(word.length() == 0) return 0;
  int count = 0;
  for (size_t i = text.find(word); i != string::npos; i = text.find(word, i + word.length()))
    count++; 
  return count;
}

int main() {
  string s;
  string t;
  cin >> s;
  int total = 0;
  while (getline(cin, t))
    total += word_count(s, t);
  cout << total << endl;
  return 0;
}

