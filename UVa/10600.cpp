#include <bits/stdc++.h>
using namespace std;
const int nax = 1e2 + 7;
typedef pair<int,int> ii;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)
#define X first
#define Y second
int link[nax], size[nax];

bool cmp(pair<int, ii> &a, pair<int, ii> &b) {
	return a.X<b.X;
}

int find(int x) {
	while (x != link[x]) x = link[x];
	return x;
}

bool same(int a, int b) {
	return find(a) == find(b);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if(size[a] < size[b]) swap(a,b);
	size[a] += size[b];
	link[b] = a;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t,n,e;
	cin>>t;
	while(t--) {
		cin>>n>>e;
		for(int i=1; i<=n; ++i) {
			link[i] = i;
			size[i] = 1;
		}
		vector<pair<int, ii>> v;
		while(e--) {
			int a,b,c;
			cin>>a>>b>>c;
			v.push_back({c, {a,b}});
		}
		sort(v.begin(), v.end(), cmp);
		int sum = 0;
		vector<pair<ii, ii>> cur;
		rep(i, v.size()) {
			int a = v[i].Y.X;
			int b = v[i].Y.Y;
		    int c = v[i].X;
			if(!same(a,b)) {
			  sum += c;
			  unite(a,b);
			  cur.push_back({{c, i}, {a,b}});
			}
		}

		int nix = INT_MAX;
		rep(i, cur.size()) {
			int t_nix = 0;
			vector<pair<int,ii>> temp = v;
			temp.erase(temp.begin()+cur[i].X.Y);
			for(int j=1; j<=n; ++j) {
				link[j] = j;
				size[j] = 1;
			}
			rep(j, temp.size()) {
				int a = temp[j].Y.X;
				int b = temp[j].Y.Y;
			    int c = temp[j].X;
				if(!same(a,b)) {
				  t_nix += c;
				  unite(a,b);
				}
			}
			bool go = 0;
			for(int j=2; j<=n; ++j) {
				if(!same(j, j-1)) {
				  go = 1;
				  break;
				}
			}
			if(!go) {
				nix = min(nix, t_nix);
			}
		}
		cout<<sum<<' '<<nix<<'\n';
	}
}
