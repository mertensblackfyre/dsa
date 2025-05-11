#include <stdio.h>

void dfs(int i);
int main(void) {

  dfs(0);

  return 0;
}

void dfs(int i) {

  int num[3] = {1, 2, 3};
  /*
  int p[7][3];


  int p1 = 0;
  int p2 = 1;
*/

  dfs(i + 1);
  dfs(i - 1);
}
