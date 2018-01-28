#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
#define X first
#define Y second
#define rep(i, n) for(int i=0; i<(int)(n); ++i)

bool f(ii &a, ii &b) {
	return a.Y < b.Y;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif

	int n, tc, s, a, b;
	cin>>n>>tc;
	vector<ii> g;
	while(n--) {
		cin>>s>>a>>b;
		int q = b -a;
		g.push_back({s, q});
	}
	sort(g.begin(), g.end(), f);
	int ans = 1;
	int q = tc;
	rep(i, g.size()) {
		
	}
}