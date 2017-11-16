#include <iostream>
using namespace std;

#define rep(i,j,n) for(int i = (j); i<(int)(n);++i)
#define repn(i,j,n) for(int i = (j); i<=(int)(n);++i)


const int maxn = 1005;

int dp[2][maxn], w[maxn], b[maxn];

int main() {
	int m,n,c,d;
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif
	cin>>m>>n>>c>>d;
	repn(i,1,m) repn(j,1,n) {
		char ch;
		cin>>ch;
		if(ch=='.') ++w[j];
		else ++b[j];
		if(i==m && j>0) {
			w[j] += w[j-1];
			b[j] += b[j-1];
		}
	}
	repn(i,1,n) dp[0][i]=dp[1][i]=INT_MAX/2;
	repn(i,1, n) repn(j,c,d) {
		if(i-j<0) continue;
		dp[0][i] = min(dp[0][i], dp[1][i-j] - w[i-j]+ w[i] );
		dp[1][i] = min(dp[1][i], dp[0][i-j] - b[i-j]+ b[i] );
	}
	cout<<min(dp[0][n],dp[1][n]);
}