#include <iostream>
#include <stdio.h>
using namespace std;
//problem
//https://cses.fi/problemset/task/1617/
//explanations why modulo 10^9 + 7
//https://japlslounge.com/posts/cses/bit_strings/1.htm
//https://www.hackerearth.com/practice/notes/abhinav92003/why-output-the-answer-modulo-109-7/
//
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
