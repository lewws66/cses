#include <cmath>
#include <iostream>
using namespace std;
// https://cses.fi/problemset/task/1070/
/*Using math investigation a permutation with n = 4
ie. 5 digits  3 1 4 2 exists but n<4 will have no solutions.
Hence the trick is to start with odd from n to 1 (-2) each time, and then start
with even n - 1 to 2 (-2)
*/
void block4(int n) {
  int i = 2, j = 1, r;
  r = n % 4;
  cout << r<<endl;
  switch (r) {
    case 1:
      cout << n << " ";
      while (i <= n-1) {
        cout << i << " " << i + 2 << " " << j << " " << j + 2 << " ";
        i += 4, j += 4;
      }
      break;
    case 2:
      cout << n-1 << " ";
      while (i <= n-2) {
        cout << i << " " << i + 2 << " " << j << " " << j + 2 << " ";
        i += 4, j += 4;
      }
      cout << n<< " ";
      break;
    case 3:
      while (i <= n - 3) {
          cout << i << " " << i + 2 << " " << j << " " << j + 2 << " ";
          i += 4, j += 4;
      }
      cout<< j << " " << j+2 << " ";
      cout <<n-1<< " ";
      break;
    default:
          while (i <= n) {
          //cout<< "Defaulted"<<endl;
          cout << i << " " << i + 2 << " " << j << " " << j + 2 << " ";
          i += 4, j += 4;
          }
    } // end switch
}
int main() {
  int n;
  cin >> n;
  if (n < 5) {
    if (n == 1) {
      cout << "1";
    } else if (n == 4) {
      cout << 3 << " " << 1 << " " << 4 << " " << 2;
    } else {
      cout << "NO SOLUTION";
    }
  } else {
      block4(n); //Comment out this line if you revert to old code
    /* old code with 2 loops
     while(i<=n){
        cout<<i<<" ";
        i+=2;
     }
      while(j<=n){
         cout<<j<<" ";
         j+=2;
      }
     */
  }
  return 0;
}
