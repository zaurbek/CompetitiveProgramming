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


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif

	string s;
	cin>>s;
	int turn  = 0;
	while(true) {
		int a[26];
		memset(a, 0, sizeof a);
		rep(i, s.size()) {
			a[s[i]-'a']++;
		}
		int odd = 0, even = 0;
		rep(i, 26) {
			if(a[i] % 2 == 1) ++odd;
			else if (a[i]>0 && a[i] % 2 == 0) ++even;
		}

		if(  odd<=1  && even >=0) {
			if(turn) cout<<"Second";
			else cout<<"First";
			return 0;
		} else {
			if(even == 0) {
				string n = "";
				int k = s.size()-1;
				while(k--) n+=" ";
				rep(i, s.size()-1) {
					n[i] = s[i+1];
				}
				s = n;
			} else {
				rep(i, s.size()) {
					if(  a[s[i]-'a'] % 2==0) {
						string n = "";
						int k = s.size();
						while(--k) n+=" ";
						bool go = 0;
						rep(j, s.size()) {
							if(j==i) {
								go = 1;
							} else {
								if(go) n[j-1] = s[j];
								else n[j] = s[j];
							}
						}
						s = n;
						break;
					}
				}
			}
			turn ^= 1;
		}

	}
	
}