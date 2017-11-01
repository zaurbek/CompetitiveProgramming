#include <bits/stdc++.h>
using namespace std;

const int N = 101;

int S[N] = {}; 

#define REP(i,n) for(int i=0; i<(int)(n); ++i)

string dp(int i, int m) {
	
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif
	char c;
	int n = 0;
	while(cin>>c) {
		S[n] = c-'0';
		++n;
	}
	cout<<dp(0, 0);
}