#include <iostream>
#include <stdio.h>
#include<cmath>
using namespace std;
//problem
//https://cses.fi/problemset/task/1754
// simultaneous linear equations 2x+y =1, 2y + x = b
// given that number of moves is x+y
// Again using scanf and printf for large data sets is 6 times faster than cin cout.
// https://cses.fi/problemset/hack/1754/entry/5177439/   (result using cin cout was 23 seconds)
//https://cses.fi/problemset/hack/1754/entry/5177470/    (result using scanf, printf was 0.03 seconds)
//
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
