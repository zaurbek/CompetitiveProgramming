#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(int)(n);++i)
const int maxn = 5e1+7;


bool f(pair<int,vector<int>> &a, pair<int,vector<int>>&b) {
	if(a.second.size()==b.second.size()) {
		return a.first>b.first;
	}
	return a.second.size()>b.second.size();
}


vector<pair<int,vector<int>>> g(maxn);

int main() {
	#define int long long
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif
	int n,m;
	cin>>n>>m;
	rep(i,n) g[i+1].first = i+1;
	while(m--) {
		int a,b;
		cin>>a>>b;
		g[a].second.push_back(b);
		g[b].second.push_back(a);
	}
	sort(g.begin(), g.end(), f);
	set<int> cur;
	cur.insert(g[0].first);
	g.erase(g.begin());
	int ans = 1;
	while(!g.empty()) {
		//iterate to find one that react
		if(g[0].first==0) break;		
		bool go = 1;
		rep(i,g.size()) {
			if(g[i].first==0) break;
			rep(j, g[i].second.size()) {
				if(cur.count(g[i].second[j])) {
					ans*=2;
					cur.insert(g[i].first);
					g.erase(g.begin()+i);
					go = false;
					break;
				}
			}
			if(!go) break;
		}
		//if none react
		if(go) {
			cur.insert(g[0].first);
			g.erase(g.begin());
		}
	}
	cout<<ans<<'\n';
}