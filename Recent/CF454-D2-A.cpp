#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,n) for(int i=0; i<(int)(n); ++i)
#define PB push_back

const int nax = 1e5;
const int EPS  = 1e-9;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

inline int nxt() {
	int x;
	cin>>x;
	return x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif

	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(d>c) {
		cout<<-1; return 0;
	}
	a *=2; b*=2; c*=2;
	for(int i=a/2; i<=a; ++i) {
		for(int j=b/2; j<=b; ++j) {
			for(int k=c/2; k<=c; ++k) {
				if(i>k && i>j && j>k && d<=i&&d<=j&&d<=k && 2*d<i && 2*d<j && 2*d>=k) {
					cout<<i<<'\n'<<j<<'\n'<<k;
					return 0;
				}
			}
		}
	}
	cout<<-1;

}