#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define PB push_back
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

const int nax = 1e5;
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

	vector<char> a;
	vector<vi> num(9);
	int cnt = 0;
	rep(i,9) {
		rep(j,9) {
			char c;
			cin>>c;
			a.PB(c);
			num[i].PB(cnt++);
		}
	}
	vector<vector<char>> n(9);
	rep(i,9) {
		rep(j,3) {
			rep(k,3) {
				n[i].PB(a[3*i + 9*j+k]);
			}
		}
	}
	int x= nxt();
	int y = nxt();
	--x; --y;
	int  res = num[x][y]%21;
	vector<int> qwe = {0,1,2,9,10,11,18,19,20};
	rep(i,qwe.size()) {
		rep(j,3) {
			if(res == qwe[i ]+3*j) {

				int d_cnt = 0;
				rep(k,qwe.size()) {
					if(a[9*res + qwe[k]]=='.') ++d_cnt;
					
				}
				if(d_cnt==0) {
					//all . with !
					rep(q,a.size()) {
						if(a[q]!='.') cout<<a[q];
						else cout<<'!';
						if(q%9 == 8) cout<<'\n';
						else if(q%3==2) cout<<' ';
						if(q!=80&& q%27==26) cout<<'\n';
					}
				} else {
					rep(k,qwe.size()) {
						if(a[9*res + qwe[k]]=='.') a[9*res + qwe[k]]='!'; 
					}
					rep(q,a.size()) {
						cout<<a[q];
						if(q%9 == 8) cout<<'\n';
						else if(q%3==2) cout<<' ';
						if(q!=80&& q%27==26) cout<<'\n';
					}
				}

				return 0;
			}
		}
	}

}