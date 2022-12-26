#include <iostream>
#include <stdio.h>
#include<cmath>
using namespace std;
//problem
//https://cses.fi/problemset/task/1754
// simultaneous linear equations 2x+y =1, 2y + x = b
// given that number of moves is x+y
int main() {
  int t, a, b;
  //cin>>t;
  scanf("%i",&t);  //replaced cin for speed 6 times faster
  while(t--){
  // cin>>a>>b;
  scanf("%i %i",&a,&b);  //replaced cin for speed 6 times faster
  //printf("%i %i\n",a,b);
  if(((2*a-b)%3==0&&(2*a-b>=0))&&((2*b-a)%3==0&&(2*b-a)>=0)||(a==0&&b==0)){
  //  cout<<"YES"<<endl;
  printf("YES\n"); //replaced cin for speed 6 times faster
  }else{
  //  cout<<"NO"<<endl;
  printf("NO\n"); //replaced cin for speed 6 times faster
  }
  }  //end while
}