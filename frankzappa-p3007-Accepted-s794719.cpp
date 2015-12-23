#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

typedef struct {
  int x;
  int y;
} queen;

bool coexist(queen * a, queen * b) {
  if (a->y == b->y)
    return false;
  if (a->x == b->x)
    return false;
  if(abs(a->x - b->x) == abs(a->y - b->y))																																																																																																																																																																																																																																
    return false;								
  return true; 
}

bool are_they_happy(queen * q) {
  for (int i = 0; i < 8; i++)
    for (int j = i + 1; j < 8; j++)
      if (!coexist(&q[i], &q[j]))
        return false;
  return true;
}

int main() {
  char board[8][8];
  queen queens[8];
  for (int i = 0; i < 8; i++)
    cin >> board[i];
  int k = 0;
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++)
      if (board[i][j] == '*') {
	    queens[k].y = i;
	    queens[k].x = j;
	    k++;
	  }
  if (are_they_happy(queens))
    printf("valid\n");
  else
    printf("invalid\n");
  return 0;
}
