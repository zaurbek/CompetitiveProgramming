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

bool f(pair<int, ii> &a, pair<int, ii> &b) {
	double r1 = (double)a.Y.Y / a.Y.X;
	double r2 = (double)b.Y.Y / b.Y.X;
	return r1>r2;
}

bool cmp(ii &a, ii &b) {
	return a.X < b.X;
}

const int nax = 1e4+10;
bool g[nax];
ii gin[nax];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif

	int n,k,x,y;
	vector<pair<int,ii>> vii;
	cin>>n;
	rep(i, n) {
		cin>>x>>y;
		vii.PB({i,{x,y}});
	}
	sort(all(vii), f);
	cin>>k;
	rep(i, k) {	
		cin>>x;
		gin[i] = {x, i};		
	}
	sort(gin, gin+k, cmp);
	int sum = 0;
	vector<ii> res;
	rep(i, k) {
		int places = gin[i].X;
		int pos = -1;
		int lm = -1;
		rep(j, sz(vii)) {
			if(g[j]) continue;
			if(places >= vii[j].Y.X) {
				if(vii[j].Y.Y > lm) {
					lm = vii[j].Y.Y;
					pos = j;
				}
			}
		}
		if(lm != -1) {
			sum += lm;
			g[pos] = 1;
			res.PB({vii[pos].X+1, gin[i].Y+1});
		}
	}
	cout<<res.size()<<' '<<sum<<'\n';
	rep(i, sz(res)) {
		cout<<res[i].X<<' '<<res[i].Y<<'\n';
	}
}