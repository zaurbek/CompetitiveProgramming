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
#define repn(i,n) for(int i=0; i<=(int)(n); ++i)

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

	string a;
	cin>>a;
	int q;
	cin>>q;
	rep(i,a.size()) {
		int pos = i;
		int maxi = a[i]-'0';
		rep(j,q) {
			int k = i+j+1;
			if(k >= a.size()) break;
			if(a[k]-'0' > maxi) {
				maxi = a[k] -'0';
				pos = k;
			}
		}
		if(pos != i) {
			q = q - (pos - i);
			while(pos != i) {
				char temp = a[pos];
				a[pos] = a[pos-1];
				a[pos-1] = temp;
				--pos;
			}
		}
	}
	cout<<a;
}