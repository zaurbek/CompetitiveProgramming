#include <bits/stdc++.h>
using namespace std;

#define repn(i,k,n) for(int i=(int)(k); i<=(int)(n); ++i)

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int x1,y1,x2,y2;
  cin>>x1>>y1>>x2>>y2;
  set<pair<int,int> > se;
  repn(i,min(x1,x2),max(x1,x2)) repn(j,min(y1,y2),max(y1,y2)) {
    if( (i==x1||i==x2) || (j==y1||j==y2) ) se.insert({i,j});
  }
  int n;
  cin>>n;
  while(n--) {
    int x,y,r;
    cin>>x>>y>>r;
    r = r*r;
    for(auto it = se.begin(); it!=se.end();) {
       double d = pow( (it->first)-x,2)+pow((it->second)-y,2);
       if(d<=r) {
         se.erase(it++);
       } else {
         ++it;
       }
    }
  }
  cout<<se.size();
}