#include <bits/stdc++.h>
using namespace std;
const int nax = 1e5+9;
int link[nax], size[nax];

int find(int x) {
	while(x!=link[x]) x =link[x];
	return x;
}

bool same(int a,int b) {
	return find(a) == find(b);
}

int unite(int a, int b) {
	a = find(a);
	b = find(b);
	if(a==b) return size[a];
	if(size[a] < size[b]) swap(a,b);
	link[b] = a;
	size[a] += size[b];
	return size[a];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin>>tc;
	while(tc--) {
		for(int i=1; i<=nax-3; ++i) {
			link[i] = i;	
			size[i] = 1;
		}
		int fr;
		cin>>fr;
		set<string> se;
		map<string, int> mp;
		int cnt = 1;
		while(fr--) {
			string s1,s2;
			cin>>s1>>s2;
			if(!se.count(s1)) {
				se.insert(s1);
				mp[s1] = cnt++;
			}
			if(!se.count(s2)) {
				se.insert(s2);
				mp[s2] = cnt++;
			}
			int a = mp[s1];
			int b = mp[s2];
			cout<<unite(a,b)<<'\n';
		}
	}	
}
