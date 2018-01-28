/*
ID: zoollhu1
LANG: C++11
TASK: gift1
*/
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(int)(n); ++i)
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	// #ifndef ONLINE_JUDGE
	// freopen("i.txt", "r", stdin);
	// freopen("o.txt", "w", stdout);
	// #endif
	freopen("gift1.in", "r", stdin);
	freopen("gift1.out", "w", stdout);
	int n;
	cin>>n;
	map<string, int> g;
	vector<string> ans(n);
	rep(i,n) cin>>ans[i];
	while(n--) {
		string man;
		cin>>man;
		int total, to;
		cin>>total>>to;
		if(to != 0) {
			g[man] += total % to;
			g[man] -= total;
		}
		rep(i, to) {
			string receive;
			cin>>receive;
			g[receive] += (total/to);
		}
	}
	rep(i,ans.size()) {
		cout<<ans[i]<<' '<<g[ans[i]]<<'\n';
	}
}