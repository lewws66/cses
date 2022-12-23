#include <iostream>
#include <cmath>
#include <iostream>
#include <cmath>
using namespace std;
//https://cses.fi/problemset/task/1094/
//
// Mistook the problem to be sorting array
/* old code inside while(j--)loop
  while(j--) {
    if(m[j-1]>m[j]){
    // cout<< m[j] << "<"<<m[j-1]<<endl;
    s = m[j];
    //cout<<"s1 ="<<s1<<endl;
    m[j] = m[j-1];
    //cout<<"m[j] ="<<m[j]<<endl;
    m[j-1]= s;
    //cout<<"m[j-1] ="<<m[j-1]<<endl;
    cmin++;    
    //cout<<j<<":"<<cmin<<endl;
    } else {
        break;  // break while(j--) loop
      }    
  }
*/
int main() {
  long int t;
  cin>> t;
  long int m[t];
  cin>>m[0];
  long int s;
  long cmin = 0;
  for(int i=1;i<t;i++) {
      cin>>m[i];
      //cout<<i<<": "<<m[i]<<endl;
      int j = i;
      //cout<<"m[j] ="<<m[j]<<endl;
      //cout<<"m[j-1] ="<<m[j-1]<<endl;
      if(m[j]<m[j-1]){
      cmin += m[j-1]-m[j]; 
          //cout<< m[j] << "<"<<m[j-1]<<endl;
      m[j] = m[j-1];
            //cout<<"s1 ="<<s1<<endl;
      //cout<<"Min moves :"<<cmin<<endl;
            //cout<<j<<":"<<cmin<<endl;
      } 
  }
  cout<<cmin<<endl;
  /*
  while(t--){
    cout<<m[t]<<"\n";
  }
  */
  return 0;
}
