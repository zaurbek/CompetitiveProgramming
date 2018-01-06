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

int dI[] = {-1, 0, 0, 1};
int dJ[] = {0, -1, 1, 0};

bool valid(int i,int j, vector<vector<char>> &g) {
	return i>=0 && j>=0 && i<g[i].size();
}

void color(char w,const ii &bg, vector<vector<char>> &g) {
	g[bg.X][bg.Y] = '#';
	for(int i=0; i<4; ++i) {
		int nI = bg.X + dI[i];
		int nJ = bg.Y + dJ[i];
		if(g[nI][nJ]==' ') {
			color(w, make_pair(nI, nJ), g);
		}
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif

	int tc;
	cin>>tc;
	cin.ignore();

	while(tc--) {
		vector<vector<char>> g(32);
		ii bg = make_pair(0,0);
		int cnt = 0;
		char w;
		while(true) {
			char c = getchar();
			while(c != '\n' && c!=EOF) {
					if(c=='*') {
						bg.X = cnt;
						bg.Y = g[cnt].size();
					}
					g[cnt].PB(c);
					c = getchar();
			}
			if(g[cnt][0]=='_') break;
			else if (g[cnt][0]!='_') w = g[cnt][0];
			++cnt;			
		}
		color(w, bg, g);
		rep(i,g.size()) {
			if(g[i].empty()) break;
			rep(j,g[i].size()) {
				cout<<g[i][j];
			}
			cout<<'\n';
		}
	}
}