#include <bits/stdc++.h>
using namespace std;
const int maxn = 150007;
vector<int> g[maxn];
bool vis[maxn];

void dfs(int a, int & cnt_vertices, int & cnt_g) {
	vis[a] = true;
	++cnt_vertices;
	cnt_g += g[a].size();
	for(int b : g[a])
		if(!vis[b])
			dfs(b, cnt_vertices, cnt_g);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif
	int n, m;
	cin>>n>>m;
	while(m--) {
		int a, b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i = 1; i <= n; ++i)
		if(!vis[i]) {
			int cnt_vertices = 0, cnt_g = 0;
			dfs(i, cnt_vertices, cnt_g);
			if(cnt_g != (long long) cnt_vertices * (cnt_vertices - 1)) {
				cout<<"NO";
				return 0;
			}
		}
	cout<<"YES";
}