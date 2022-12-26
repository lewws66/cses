#include <iostream>
#include <stdio.h>
using namespace std;
//problem
//https://cses.fi/problemset/task/1617/
//explanation
//https://japlslounge.com/posts/cses/bit_strings/1.htm
int main() {
int n;
int s=2;
  cin>>n;
  while(n-- -1){
  s *= 2;
  s %= 1000000007;
  }
  cout<<s;
}
