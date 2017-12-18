#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)
int g[26][2];
string s1,s2;

bool del() {
	int cnt = 0;
	rep(i, s1.size()) {
		if(s1[i]==s2[cnt]) ++cnt;
		if(cnt==s2.size()) return 1;
	}
	return 0;	
}

bool same_let() {
	rep(i,26) if(g[i][0]!=g[i][1]) return false;
	return true;
}

bool has() {
	rep(i,26) if(g[i][0]<g[i][1]) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif
	cin>>s1>>s2;
	rep(i,s1.size()) ++g[s1[i]-'a'][0];
	rep(i,s2.size()) ++g[s2[i]-'a'][1];
	if(del()) cout<<"automaton"; 
	else if(same_let()) cout<<"array"; 
	else if(has()) cout<<"both"; 
	else cout<<"need tree";
}