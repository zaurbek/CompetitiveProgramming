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

	int n,k;
	cin>>n>>k;
	ll a[n+1];
	rep(i, n) cin>>a[i+1];
	partial_sum(a, a+n+1, a);
	ll ans = 0;
	map<ll, int> g;
	if(k==1) {
		for(int i=n; i>=0; --i) {
			if(g.find(a[i]+1) != g.end())
				ans += g[a[i]+1];
			++g[a[i]];
		}		
	} else if (k==-1) {
		for(int i=n; i>=0; --i) {
			if(g.find(a[i]+1)!=g.end())
				ans += g[a[i]+1];
			if(g.find(a[i]-1)!=g.end())
				ans+=g[a[i]-1];

			++g[a[i]];
		}
	} else {
		for(int i=n; i>=0; --i) {
			ll m = 1;
			while(true) {
				if(abs(m)>=1e15) break;
				if(g.find(a[i]+m) != g.end())
					ans += g[a[i]+m];
				m *= k; 
			}
			++g[a[i]];
		}
	}
	cout<<ans;

}