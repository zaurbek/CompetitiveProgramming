#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);    
  #ifndef ONLINE_JUDGE
  freopen("i.txt", "r", stdin);
  freopen("o.txt", "w", stdout);
  #endif
  int n, a;
  cin>>n;
  set<int> se;
  while(n--) {
    cin>>a;
    se.insert(a);
  }
  if(se.size()==1 || se.size()==2 || (se.size()==3 && 2*se[1] == se[0]+se[2])  ) cout<<"YES";
  else cout<<"NO";
}