#include <iostream>
#include <cstring>
using namespace std;

const int N = 201;

int a,b, price[25][25];
bool dp[25][N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	while(n--) {
		cin>>a>>b;
		for(int i=0; i<b; ++i) {
			cin>>price[i][0];
			for(int j=1; j<=price[i][0]; ++j) cin>>price[i][j];
		}
		memset(dp, false, sizeof dp);
		for(int i=1; i<=price[0][0]; ++i) 
			if(a-price[0][i]>=0) 
				dp[0][a-price[0][i]] = true;
		for(int g=1; g<b; ++g) { 
			for(int k=0; k<a; ++k) 
				if(dp[g-1][k])
					for(int i=1; i<=price[g][0]; ++i) {
						if(k-price[g][i]>=0) {
							if(k-price[g][i]>=0) dp[g][k-price[g][i]] = true;
						}
					}
		}
		int cnt = 0;
		for(int i=0; i<N; ++i) {
			if(dp[b-1][i]) break;
			++cnt;
		}
		if(cnt==N) cout<<"no solution\n";
		else cout<<a-cnt<<'\n';
	}
}