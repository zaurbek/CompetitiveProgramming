#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin>>n;
  ll res = 1, cnt = 0;
  ll lastOne = -1;
  rep(i,n) {
    ll a;
    cin>>a;
    if(a==0) {
      ++cnt;
    } else {
      if(lastOne != -1) {
        res *= (cnt+1);
      }
      cnt=0;
      lastOne = i;
    }
  }
  if(lastOne==-1) res = 0;
  cout<<res<<'\n';
}