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

bool prime(int n) {
	if(n<2) return false;
	if(n%2 ==0&&n>2) return false;
	int q = sqrt(n);
	for(int i=3; i<=q; i+=2) {
		if(n%i == 0) return false;
	}
	return true;
}

void solve(int x) {
	if(x<8) cout<<"Impossible.\n";
	else {
		if(x%2==0) {
			cout<<2<<' '<<2<<' ';
			x-=4;
			for(int i=2; i<=x/2; ++i) {
				if(prime(i) && prime(x-i)) {
					cout<<i<<' '<<x-i<<'\n';
					return;
				}
			}
		} else {
			cout<<2<<' '<<3<<' ';
			x-=5;
			for(int i=2; i<=x/2; ++i) {
				if(prime(i) && prime(x-i)) {
					cout<<i<<' '<<x-i<<'\n';
					return;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif

	int x;
	while(cin>>x) {
		solve(x);
	}

}