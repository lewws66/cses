#include <iostream>
#include<cmath>
using namespace std;
//https://cses.fi/problemset/task/1618
int main() {
  long int n, z=0;
  cin>>n;
  while(n>=5){
    n = round(n/5);
    z += n;
  }
  cout<<z;
}