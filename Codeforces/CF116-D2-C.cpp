#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
#define X first
#define Y second
#define PB push_back
#define eps 1e-9
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

inline int read() {
    int ret=0,c,f=1;
    for(c=getchar(); !(isdigit(c)||c=='-'); c=getchar());
    if(c=='-') f=-1,c=getchar();
    for(; isdigit(c); c=getchar()) ret=ret*10+c-'0';
    if(f<0) ret=-ret;
    return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif

	int n;
	cin>>n;
	set<int> g;
	for(int i=1; i<=n; ++i) g.insert(i);
	int a[n+1];
	for(int i=1; i<=n; ++i) {
		int x;
		cin>>x;
		a[i] = x;
		g.erase(x);
	}
	int ans = 1;
	for(auto it = g.begin(); it!=g.end(); ++it) {
		int cnt = 1;
		int beg = *it;
		while(a[beg]!=-1) {
			++cnt;
			beg = a[beg];
			ans = max(ans, cnt);
		}
	}
	cout<<ans;
}