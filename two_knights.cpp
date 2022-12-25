#include <stdio.h>
//https://cses.fi/problemset/task/1072
//solution : https://japlslounge.com/posts/cses/two_knights/1.htm

int main() {
long int k, n;
scanf("%li", &k);      
  for(long int i = 1; i <= k; i++){
    n = (i * i) * (i* i - 1) / 2 - (4 * (i - 2) * (i - 1));
    printf("%li\n", n);
  }
}