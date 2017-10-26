#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif
    string str;
    cin>>str;
    int cnt = 0, res = 0;
    int n = str.size();
    REP(i, n) {
        if(str[i]=='(') ++cnt;
        else if(cnt>0) {
        	--cnt;
        	++res;
        }
    }
    cout<<2*res;
}