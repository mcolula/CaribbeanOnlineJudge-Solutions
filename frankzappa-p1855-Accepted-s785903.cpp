#include <iostream>
#include <cstdio>
#include <queue>
#include <set>

using namespace std;

multiset<int> nums;
queue<int> res;
int i = 0;

void insert(int n) {
  if (((int) nums.count(n)) == 0)
    nums.insert(n);
  else {
    res.push(n); 
    i++;
  }
}


int main() {
  int t, n;
  int numb;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    while (n--) {
	  scanf("%d", &numb);
	  insert(numb);
	}
    if (i == 0) res.push(-1);
	nums.clear();
	i = 0;
  }
  int i;
  while (!res.empty()){
    i = res.front();
    res.pop();
    if(i == -1)
      printf("Not found!\n");
    else
      printf("%d\n", i);
  }
  return 0;
}

