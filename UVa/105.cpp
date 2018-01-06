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
const int nax = 1e5+10;

inline int read() {
    int ret=0,c,f=1;
    for(c=getchar(); !(isdigit(c)||c=='-'); c=getchar());
    if(c=='-') f=-1,c=getchar();
    for(; isdigit(c); c=getchar()) ret=ret*10+c-'0';
    if(f<0) ret=-ret;
    return ret;
}

int ans[nax];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif

	int a,b,c;
	while(cin>>a>>b>>c) {
		for(int i=a; i<c; ++i) {
			ans[i] = max(ans[i], b);
		}
	}
	int cnt = 0;
	int cur = 0;

	rep(i, nax) {
		if(ans[i] != cur) {
			if(cnt++) cout<<' ';
			cout<<i;
			cout<<' '<<ans[i];
			cur = ans[i];
		}
	}
	cout<<'\n';
}