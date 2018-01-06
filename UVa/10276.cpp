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

bool is_perfect_square(int n) {
    if (n < 0)
        return false;
    int root = round(sqrt(n));
    return n == root * root;
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
		int n;
		cin>>n;
		vector<stack<int>> v(n);
		int cnt = 1;
		while(true) {
			bool go = 1;
			rep(i, sz(v)) {
				if(v[i].empty()) {
					v[i].push(cnt++);
					go = 0;
					break;
				} else {
					int s = v[i].top();
					if(is_perfect_square(s+cnt)) {
						go = 0;
						v[i].push(cnt++);
						break;	
					}
				}	
			}			
			if(go) {
				cout<<cnt-1<<'\n';
				break;
			}
		}
	}	
}