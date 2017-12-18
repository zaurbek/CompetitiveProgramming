#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define X first
#define Y second

const int nax = 1e3+7;
int link[nax], size[nax];

int find(int x) {
	while(x!=link[x]) x= link[x];
	return x;
}

bool same(int a, int b) {
	return find(a) == find(b);
}

bool cmp(pair<double, ii> &a, pair<double, ii> &b) {
	return a.X<b.X;
}

void unite(int a, int b) {
	a= find(a);
	b=  find(b);
	if(size[a] < size[b]) swap(a,b);
	size[a] += size[b];
	link[b] = a;
}

int main() {
	int tc;
	cin>>tc;
	while(tc--) {
		int n;
		cin>>n;
		ii a[n];
		for(int i=0; i<n; ++i) {
			int x,y;
			cin>>x>>y;
			a[i] = {x,y};
		}
		int e;
		cin>>e;
		for(int i=1; i<=n; ++i) {
			link[i] = i;
			size[i] = 1;
		}
		int to_do = n;
		for(int i=0; i<e; ++i) {
			ll from, to;
			cin>>from>>to;
			++from; ++to;
			unite(from, to);
		}
		vector<pair<double,ii>> g;
		//in o(n^2) time make all possible edges
		for(int i=1; i<=n; ++i) {
			for(int j=1; j<=n; ++j) {
				if(i!=j) {
					if(!same(i, j)) {
						double dis = sqrt( pow(a[i].X-a[j].X,2) - pow(a[i].Y-a[j].Y,2));
						g.push_back({dis, {i,j}});
					}
				}
			}
		}
		sort(g.begin(), g.end(), cmp);
		vector<ii> res;
		for(int i=0; i<g.size(); ++i) {
			if(!same(g[i].Y.X, g[i].Y.Y)) {
				unite(g[i].Y.X, g[i].Y.Y);
				res.push_back({g[i].Y.X, g[i].Y.Y});
			}
		}
		if(res.empty()) {
			cout<<"No new highways need\n";
		} else {
			for(int i=0; i<res.size(); ++i) {
				cout<<res[i].X<<' '<<res[i].Y<<'\n';
			}
		}
		cout<<'\n';
	}
}
