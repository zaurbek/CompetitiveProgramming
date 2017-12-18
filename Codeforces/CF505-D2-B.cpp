#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define X first
#define Y second
#define rep(i,n) for(int i=0; i<(int)(n); ++i)
typedef pair<int,int> ii;
const int maxn = 1e2+7;

vector<int> g[maxn][maxn];
bool vis[maxn][maxn];

int bfs(int from, int finale) {
	memset(vis, false, sizeof vis);
	queue<ii> q;
	//{ color, current node};
	rep(i, maxn) {
		if(!g[from][i].empty()) {
			rep(j,g[from][i].size()) {
				q.push({g[from][i][j],i}); //color of path, and node
			}
		}
	}
	int cnt = 0;
	while(!q.empty()) {
		ii s = q.front(); q.pop();
		if(vis[s.Y][s.X]) continue;
		vis[s.Y][s.X] = 1;
		if(s.Y==finale) {
			++cnt;
			continue;
		}
		rep(i, maxn) {
			if(!g[s.Y][i].empty()) {
				rep(j, g[s.Y][i].size()) {
					if(g[s.Y][i][j]==s.X)
						q.push({g[s.Y][i][j], i}); 
				}
			}
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif
	int n,m;
	cin>>n>>m;
	while(m--) {
		int a,b,c;
		cin>>a>>b>>c;
		g[a][b].PB(c);
		g[b][a].PB(c);
	}
	int q, res = -1;
	cin>>q;
	while(q--) {
		int from, end_;
		cin>>from>>end_;
		res = bfs(from, end_);
		cout<<res<<'\n';
	}
}