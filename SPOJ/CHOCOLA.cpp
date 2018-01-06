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

bool f(const pair<int,int> &a,const pair<int,int> &b) {
	return a.Y > b.Y;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif

	int tc;
	cin>>tc;
	while(tc--) {
		int m,n, x;
		cin>>m>>n;
		vector<ii> v;
		rep(i, m-1) {
			cin>>x;
			v.PB(make_pair(0, x));
		}	
		rep(i, n-1) {
			cin>>x;
			v.PB(make_pair(1, x));
		}
		sort(all(v), f);
		ll mY = 1, mX = 1;
		ll sum = 0;
		rep(i, sz(v)) {
			if(v[i].X == 0) {
				++mY;
				sum += mX*v[i].Y;
			} else {
				++mX;
				sum += mY*v[i].Y;
			}
		}
		cout<<sum;
		if(tc) cout<<'\n';
	}
}