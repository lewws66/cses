#include <iostream>
using namespace std;
// Studying how two lines of input is being read in two lines as follows 
// and how while(t--) works
// 6
// 12 13 14 15 66 77
//
int main() {
  // read integer n
  int t;
  cin>> t;
  int m[t];
  for(int i=0;i<t;i++) {
      cin>>m[i];
      cout<<i<<" "<<m[i]<<endl;
  }
  while(t--){
      cout<<t<<" : "<<m[t]<<endl;
  }
  return 0;
}
