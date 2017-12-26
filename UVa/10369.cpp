#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
typedef pair<int,int> ii;
#define X first
#define Y second
const int nax = 1e4;

int link[nax], size[nax];

int find(int i) {
	while(i!=link[i]) i=link[i];
	return i;
}

bool same(int a, int b) {
	return find(a)==find(b);
}

void unite(int a, int b) {
	a=find(a); b=find(b);
	if(size[a] < size[b]) swap(a,b);
	link[b] = a;
	size[a] += size[b];
}

bool f(pair<int, ii> &a, pair<int, ii> &b) {
	return a.X < b.X;
}


int main() {
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif
	int t;
	scanf("%d", &t);
	while(t--) {
		int s,e;
		scanf("%d %d", &s, &e);
		for(int i=1; i<=e; ++i) {
			link[i] = i;
			size[i] = 1;
		}
		int total = 0;
		vector<pair<int,ii>> g1;
		vector<ii> a;
		for(int i=0; i<e; ++i) {
			int x,y;
			scanf("%d %d", &x, &y);
			a.push_back({x,y});
		}
		for(int i=0; i<a.size(); ++i) {
			for(int j=i+1; j<a.size(); ++j) {
				int base = (a[i].X-(int)a[j].X)*((int)a[i].X-a[j].X) + \
					(a[i].Y-(int)a[j].Y)*(a[i].Y-(int)a[j].Y);
				g1.push_back({base, {i+1, j+1}});
			}
		}
		sort(g1.begin(), g1.end(), f);
		stack<int> q;
		for(int i=0; i<g1.size(); ++i) {
			if(!same(g1[i].Y.X, g1[i].Y.Y) ) {
				unite(g1[i].Y.Y, g1[i].Y.X);
				++total;
				q.push(g1[i].X);
				if(total == e-s) break;
			}
		}
        double res = sqrt(q.top());
        printf("%.2f\n",res);
	}
}