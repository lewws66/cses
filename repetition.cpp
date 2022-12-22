#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main() {
  string dna; cin>>dna;
  int n = dna.length();//total number of characters
  int m =1, maxrep = 1 ; //maxrep longest repetition to be found
  while(n-- -1) {
    if(dna[n]==dna[n-1]){
      m++;
      maxrep = max(m,maxrep);
    //  cout<<"maxrep ="<<maxrep<<endl;
    }else {
      m =1; //reset m if sequence is broken
    }
   // cout<<dna[n]<<"  "<<dna[n-1]<<endl;
   // cout << n<<endl;
  }
  cout<< maxrep;
}