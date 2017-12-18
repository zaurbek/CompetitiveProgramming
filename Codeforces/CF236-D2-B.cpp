#include <bits/stdc++.h>
using namespace std;
#define repn(i,k,n) for(int i=(k); i<=(int)(n); ++i)

const int N = 1e6+7;
const int divis = llround(pow(2,30));

int dp[N];

int n_div(int n) {
  int sq = llround(sqrt(n));
  int cnt = 0;
  repn(i,1,sq) {
    if(n%i==0) {
      ++cnt;
      if(i != n/i) ++cnt;
    }
  }
  return dp[n] = cnt;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);    
  #ifndef ONLINE_JUDGE
  freopen("i.txt", "r", stdin);
  freopen("o.txt", "w", stdout);
  #endif
  int a,b,c;
  cin>>a>>b>>c;
  long long sum = 0;
  repn(i,1,a) repn(j,1,b) repn(k,1,c) {
    int res = i*j*k;
    if(dp[res]!=0) sum+=(dp[res]%divis);
    else sum+= (n_div(res)%divis);
  }
  sum %= divis;
  cout<<sum;
}