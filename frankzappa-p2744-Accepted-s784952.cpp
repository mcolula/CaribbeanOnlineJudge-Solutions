#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

bool cmp(int i, int j) { 
  return i > j;
}

int days(int a[], int n) {
  sort(a, a + n, cmp);
  int day = 0;
  int sum = 0;
  for (int i = 0; i < n; i++) { 
    sum = i + a[i] + 1;
    if(sum > day)
      day = sum;
  }
  return day;
}

int main() {
  int t;
  scanf("%d", &t);
  int * seeding = new int[t];
  for (int i = 0; i < t; i++)
    scanf("%d", &seeding[i]);
  printf("%d\n", days(seeding, t) + 1);
  return 0;
}

