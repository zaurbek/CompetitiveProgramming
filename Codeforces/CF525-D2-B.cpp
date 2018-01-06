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

	string s;
	int m;
	cin>>s>>m;
	int n  =s.size();
	int x;
	int sum[s.size()];
	memset(sum, 0, sizeof sum);
	while(m--) {
		cin>>x;
		++sum[x-1];
	}
	ll res = 0;
	rep(i, n/2) {
		res+=sum[i];
		if(res&1) {
			swap(s[i], s[n-i-1]);
		}
		cout<<s[i];
	}

}