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
	char r=' ';
	int cnt_l = 0, cnt_r = 1;
	rep(i, sz(s)) {
		if(r==' ')
			r=s[i];
		else if (s[i]!=r) {
			r = s[i];
			cnt_l = cnt_r;
			cnt_r = 1;
		} else {
			++cnt_r;
			if(cnt_r>=3) {
				--cnt_r;
				s[i]='-';
			}
			else if (cnt_r >=2 && cnt_l==2) {
				--cnt_r;
				s[i]='-';
			}
		}
	}
	rep(i, sz(s)) {
		if(s[i]!='-') cout<<s[i];
	}
}