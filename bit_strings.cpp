#include <iostream>
#include <stdio.h>
using namespace std;
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