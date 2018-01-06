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

bool f(ii &a, ii &b) {
	return a.Y < b.Y;
}

int n,r,avg;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif

	n = read();
	r = read();
	avg = read();
	ll total = (ll)n * avg;
	vector<ii> q;
	while(n--) {
		int a = read();
		int b = read();
		q.PB({a,b});
		total -= a;
	}
	ll cnt = 0;
	sort(all(q), f);
	int pos = 0;
	while(total >0) {
		while(q[pos].X==r) ++pos;
		if(total - r+q[pos].X <0) {
			cnt+=(ll)q[pos].Y*(total);
			break;
		} else {
			total -= (r-q[pos].X);
			cnt+=(ll)q[pos].Y*(r-q[pos].X);
			q[pos++].X = r;
		}
	}
	cout<<cnt;
}