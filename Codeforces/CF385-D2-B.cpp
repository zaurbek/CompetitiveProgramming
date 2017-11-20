#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(int)(n); ++i)

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif
	string str;
	cin>>str;
	int cnt = 0, pos = 0;
	rep(i,str.size()-3) if(str.substr(i,4)=="bear") {
			int res = ((i+1)-pos)*(str.size()-i-3);
			pos = i+1;
			cnt += res;
	}
	cout<<cnt;
}