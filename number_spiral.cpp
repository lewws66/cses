// #include <iostream>
// #include <cmath>
# include <stdio.h> // replaced iostream and cmath
//using namespace std; // commented out when using stdio.h
// https://cses.fi/problemset/task/1071/
int main() {
  long t, x, y, r;
  // cin>>t;  // replaced by scanf("%li", &t);
  scanf("%li", &t);  
  while(t--){
    //cout << "Hello World!\n";
    // cin>>x>>y;  scanf("%li %li", &y,&x);
    scanf("%li %li", &x,&y);
    if(x>y){
      if(x%2==1){
        r=(x-1)*(x-1)+y; //pow(x-1,2) has truncation errors
      }else{
        r=x*x-y+1;
      }
    }else if(y%2==1){
        r=y*y-x+1;
    }else{
        r=(y-1)*(y-1)+x;
    }
    //cout<<r<<endl; //printf("%lli\n", ans)
    printf("%li\n", r);
  }
  return 0;
}