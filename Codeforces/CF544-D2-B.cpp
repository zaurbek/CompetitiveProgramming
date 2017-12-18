#include <bits/stdc++.h>
using namespace std;

const int N = 1e2+7;
int n,k;
bool g[N][N];

bool valid(int i, int j) {
  if(i!=0 && g[i-1][j]) return false;
  if(j!=0 && g[i][j-1]) return false;
  if(i!=n-1 && g[i+1][j]) return false;
  if(j!=n-1 && g[i][j+1]) return false;
  return true;
}

int main() {
  cin>>n>>k;
  if(k==0) {
    cout<<"YES\n";
    for(int i=0; i<n; ++i) { 
      for(int j=0; j<n; ++j) {
        cout<<'S';   
      }
      cout<<'\n';
    }
    return 0;
  }
  for(int i=0; i<n; ++i) {
    for(int j=0; j<n; ++j) {
      if(valid(i,j)) {
        --k;
        g[i][j] = true; 
        if(k==0) {
          cout<<"YES\n";
    for(int i=0; i<n; ++i) {
      for(int j=0; j<n; ++j) {
        if(g[i][j]) cout<<'L';
        else cout<<'S';
      }
      cout<<'\n';
    }
    return 0;
        }
      }
    }
  }
  cout<<"NO";
}