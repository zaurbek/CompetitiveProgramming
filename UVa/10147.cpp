#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(int)(n); ++i)
#define X first
#define Y second
#define PB push_back
typedef long long ll;
typedef pair<int,int> ii;

const int nax = 1e4;
int link[nax], size[nax];

bool f(pair<ll, ii> &a, pair<ll, ii> &b) {
	return a.X < b.X;
}

int find(int x) {
	while(x!=link[x]) x=link[x];
	return x;
}

bool same(int a, int b) {
	return find(a)==find(b);
}

void unite(int a, int b) {
	a = find(a); b = find(b);
	if(size[a] < size[b]) swap(a,b);
	size[a] += size[b];
	link[b] = a;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) {
		int n, e;
		cin>>n;
		rep(i,n) {
			link[i+1] = i+1;
			size[i+1] = 1;
		}
		ii a[nax];
		rep(i,n) {
			int x,y;
			cin>>x>>y;
			a[i+1] = {x,y};
		}
		cin>>e;
		rep(i,e) {
			int x, y;
			cin>>x>>y;
			if(!same(x,y)) unite(x,y);
		}
		vector<pair<ll, ii>> g;
		for(int i=1; i<=n; ++i) {
			for(int j=i+1; j<=n; ++j) {
				if(!same(i,j)) {
					ll base = (a[i].X-(ll)a[j].X)*((ll)a[i].X-a[j].X) + \
					(a[i].Y-(ll)a[j].Y)*(a[i].Y-(ll)a[j].Y);
					ll dis = base*base;
					g.PB({dis, {i, j}});
				}
			}
		}
		sort(g.begin(), g.end(), f);
		rep(i,g.size()) {
			int a = g[i].Y.X;
			int b = g[i].Y.Y;
			if(!same(a,b)) {
				unite(a,b);
				cout<<a<<' '<<b<<'\n';
			}
		}
		if(g.empty()) cout<<"No new highways need\n";
		if(t) cout<<'\n';
	}
}
