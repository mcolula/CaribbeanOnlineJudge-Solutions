#include <iostream>
#include <cstdio>

using namespace std;

int main() { 
  int survivor;
  int people;
  scanf("%d", &people);
  int alive;
  scanf("%d", &alive);
  if(people <= alive) {
    printf("*\n");
    return 0;
  }
  bool lost[people];
  for(int i = 0; i < people; i++)
    lost[i] = true;
  for(int i = 0; i < alive; i++) {
    scanf("%d", &survivor);
    lost[survivor - 1] = false; 
  }
  for(int i = 0; i < people; i++)
    if(lost[i])
      printf("%d ", i + 1);
  printf("\n");    
  return 0;
}
