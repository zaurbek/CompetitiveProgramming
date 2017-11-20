#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)
int a[100100][2]; 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, cnt = 0;
    cin>>n;
    memset(a, -1, sizeof a);
    rep(i,n) {
      int temp;
      cin>>temp;
      if(a[temp][0]==-1&&a[temp][0]!=-3000) {
        a[temp][0] = i;
        a[temp][1] = 0;
        ++cnt;
      } else if (a[temp][0]>-1) {
        int res = i-a[temp][0];
        if(a[temp][1]==0 || a[temp][1]==res) {
        	  a[temp][1] = res;
        	  a[temp][0] = i;
        } else if(a[temp][1]!=res) {
        	  a[temp][0] = -3000;
        	  --cnt;
        }
      }
    }
    cout<<cnt<<'\n';
    rep(i,100100) {
      if(a[i][0]!=-1&&a[i][0]!=-3000) {
        cout<<i<<' '<<a[i][1]<<'\n';
      }
    }
}