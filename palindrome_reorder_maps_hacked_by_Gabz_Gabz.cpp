#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define mod 1000000007
#include<bits/stdc++.h>
using namespace std;
// this code is from Gabz_Gabz	C++17	0.02 s
// https://cses.fi/problemset/hack/1755/entry/5191454/
//
//
#define ll long long
void solve()
{ string str;
  cin>>str;
  ll n=(ll)str.length();
  unordered_map<char,ll> mp;
  for(ll i=0;i<n;i++)
  { mp[str[i]]++;
 
  }
  ll oddc=0;
  for(auto itr=mp.begin();itr!=mp.end();itr++)
  { if(itr->second%2)
    oddc++;
 
  }
  if(oddc == 0 || ((n&1) && oddc==1))
  { auto ans=str;
    ll l,r;
    l=0;
    r=n-1;
    for(auto itr=mp.begin();itr!=mp.end();itr++)
    { ll temp=itr->second;
      if(temp%2==1)
      { ans[(n-1)/2]=itr->first;
        temp--;
 
      }
      while(temp)
      { ans[l]=ans[r]=itr->first;
        l++;
        r--;
        temp-=2;
 
      }
 
    }
    cout<<ans<<"\n";
    
 
  }
  else
  cout<<"NO SOLUTION\n";
 
    
}
 int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int ttestvar=1;
   //cin>>ttestvar;
   //cout<<ttestvar<<"\n";
   //sieve();
   while(ttestvar--)
   { solve();
 
   }
}