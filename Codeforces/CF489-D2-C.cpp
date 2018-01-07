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

	int l, s;
	cin>>l>>s;
	--s;
	if(s<0) {
		if(l==1) cout<<0<<' '<<0;
		else cout<<-1<<' '<<-1;
		return 0;
	}
	int a[l] = {};
	a[0] = 1;
	string ans = "";
	rep(i, l) {
		while(a[i]<9 && s>0) {
			--s;
			++a[i];
		}
		ans+=to_string(a[i]);
	}
	if(s>0) {
		cout<<-1<<' '<<-1;
		return 0;
	}
	bool g = 0;
	for(int i=l-1; i>=0; --i) {
		if(a[i]!=0) {
			g = 1;
		} else if (!g && a[i]==0) {
			int sc = i-1;
			while(a[sc]==0) {
				--sc;
			}
			--a[sc];
			g = 1;
			a[i] = 1;
		}
		cout<<a[i];
	}
	cout<<' '<<ans;	
}