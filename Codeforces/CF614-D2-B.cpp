#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif

	int n;
	cin>>n;
	int zer = 0;
	string wrong = "-1";
	while(n--) {
		string s;
		cin>>s;
		if(s[0] == '0' ) {
			cout<<0; return 0;
		} else if(s[0] == '1') {
			bool go =  0;
			for(int i=1; i<(int)s.size(); ++i) {
				if(s[i]!='0') {
					go = 1;
					break;
				}
			}
			if(!go) {
				zer += s.size() -1;
			} else {
				wrong = s;
			}
		} else {
			wrong = s;
		}
	}
	string ans = "";
	if(wrong!="-1") ans = wrong;
	else ans = "1"
	while(zer--) ans+="0";
	cout<<ans;
}