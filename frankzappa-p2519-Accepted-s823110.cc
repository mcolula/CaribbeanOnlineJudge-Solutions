#include <iostream>
#include <stack>
#include <queue>

using namespace std;

bool vocal(char c) { return c >= '0' && c <= '9'; }

int operation(int a, int b, char c) {
  if (c == '+') return a + b;
  if (c == '-') return a - b;
  if (c == '*') return a * b;
}

int eval(string s) {
  int a, b;
  string num = "";
  stack<int> values;
  for (int i = 0; i < s.size(); i++) {
    if (vocal(s[i])) {
	  while (vocal(s[i]) && i < s.size())
	    num += s[i++];
	  values.push(stoi(num));
	  num = "";
    }
    if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
      a = values.top(); values.pop();
      b = values.top(); values.pop();
      values.push(operation(b, a, s[i]));
    }
  }
  return values.top();
}

int eval_queue(string s) {
  int a, b;
  string num = "";
  queue<int> values;
  for (int i = 0; i < s.size(); i++) {
    if (vocal(s[i])) {
	  while (vocal(s[i]) && i < s.size())
	    num += s[i++];
	  values.push(stoi(num));
	  num = "";
    }
    if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
      a = values.front(); values.pop();
      b = values.front(); values.pop();
      values.push(operation(b, a, s[i]));
    }
  }
  return values.front();
}

int eval_pq(string s) {
  int a, b;
  string num = "";
  priority_queue<int, vector<int>, std::greater<int>> values;
  for (int i = 0; i < s.size(); i++) {
    if (vocal(s[i])) {
	  while (vocal(s[i]) && i < s.size())
	    num += s[i++];
	  values.push(stoi(num));
	  num = "";
    }
    if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
      a = values.top(); values.pop();
      b = values.top(); values.pop();
      values.push(operation(b, a, s[i]));
    }
  }
  return values.top();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  string s;
  cin >> t;
  while (t--) {
    getline(cin >> ws, s);
    cout << eval(s) << " " << eval_queue(s) << " " << eval_pq(s) << "\n";
  }
  return 0;
}

