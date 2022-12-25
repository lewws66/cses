//#include <iostream>
#include <stdio.h>
//using namespace std;
//https://cses.fi/problemset/task/1092
//
bool checkSumDivide(long int n) {
long int s = n*(n+1)/2;
if(s%2==0) {
    printf("YES\n");
    //printf("Sum %li is %li and YES can be equally divided.\n",n, s);  
  return true;
} else {
    printf("NO\n");
    //printf("No, sum of %li  %li cannot be divided equally. \n",n,s);
  return false;
  }
}

int main() {
long int n;
  scanf("%li",&n);
  if(checkSumDivide(n)) {
       if(n%4==3) {
         printf("%li\n",(n+1)/2);
         for(long int i=1; i<=n; i++){
          if((i%4==0)||(i==1)||(i==2)||((i%4==3)&&(i>3))){
             printf("%li ",i);
          }
        }
        printf("\n%li\n",n-(n+1)/2);
        for(long int i=1; i<=n; i++){ 
         if(((i%4==1)&&(i>1))||(i==3)||((i%4==2)&&(i>2))){
            printf("%li ",i);
         }
        }
     }// 1st case if(n%4==3)
      else{
         printf("%li\n",n/2);
         for(long int i=1; i<=n; i++){
          if((i%4==0)||(i%4==1)){
             printf("%li ",i);
          }
        }
        printf("\n%li\n", n/2);
        for(long int i=1; i<=n; i++){ 
         if((i%4==2)||(i%4==3)){
            printf("%li ",i);
         }
        }
      }
  }  // end if(checkSumDivide)
  return 0;
} //end of main