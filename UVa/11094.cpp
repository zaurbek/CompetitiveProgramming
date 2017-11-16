#include <iostream>
#include <cstring>
using namespace std;
#define rep(i,n) for(int i=0; i<n; ++i)
const int maxn = 21;
 
int a,b,c,d;
char g[maxn][maxn];
char land, water;
bool visited[maxn][maxn];
 
int dY[]={-1,0,0,1};
int dX[]={0,-1,1,0};
 
bool valid(int i, int j) {
  return i>=0&&j>=0&&i<a&&j<b;
}
 
int dfs(int i, int j) {
  visited[i][j] = true;
  int sum = 0;
  if(i==c && j==d) sum =-100000;
  rep(k,4) {
    int nI = i + dY[k];
    int nJ = j + dX[k];
    if(valid(nI,nJ) && g[nI][nJ] == land && !visited[nI][nJ]) {
      sum += dfs(nI, nJ)+1;
    } else if (valid(nI, 0) && nJ==b && g[nI][0] == land && !visited[nI][0]) {
      sum += dfs(nI, 0) + 1;
    } else if (valid(nI, b-1) && nJ==-1 && g[nI][b-1] == land && !visited[nI][b-1]) {
      sum += dfs(nI, b-1) + 1;
    }
  }
  return sum;
}
 
int main() {
  while(cin>>a>>b) {
    memset(visited, false, sizeof visited);
    rep(i,a) cin>>g[i];
    cin>>c>>d;
    land = g[c][d];
    rep(i,a) rep(j,b) {
      if(g[i][j]!=land) {
        water = g[i][j];
        break;
      }
    }
    int res = 0;
    rep(i,a) rep(j,b) {
      if(g[i][j]==land && !visited[i][j]) {
        res = max(res, 1+dfs(i,j));
      }
    }
    cout<<res<<'\n';
  }
}