#include <bits/stdc++.h>
using namespace std;
const int nax = 100;

#define rep(i,n) for(int i=0; i<(int)(n); ++i)

char g[nax][nax];
bool vis[nax][nax];

pair<int,int> del[4] = { {-1,0},{0, -1},{0,1},{1,0}  };
const int nem = 4;

int n,m;

bool legit(int i, int j) {
	return i>=0&&j>=0&&i<n&&j<m;
}

bool endq = 0;

void dfs(char c, int i, int j, int from) {
	if(vis[i][j]) {
		cout<<"Yes";
		endq = 1;
		return;
	}
	vis[i][j] = true;
	rep(q,nem) {
		if(from==0 && q==3) continue;
		if(from==1 && q==2) continue;
		if(from==2 && q==1) continue;
		if(from==3 && q==0) continue;
		int nI = i+del[q].first;
		int nJ = j+del[q].second;
		if(legit(i,j) && g[nI][nJ] == c) {
			dfs(c, nI, nJ, q);
			if(endq) return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif

	cin>>n>>m;
	rep(i,n) cin>>g[i];

	rep(i,n) rep(j,m) {
		if(!vis[i][j]) {
			dfs(g[i][j], i, j, -1);
		}
		if(endq) return 0;
	}
	cout<<"No";
}