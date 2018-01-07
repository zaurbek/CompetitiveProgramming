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

string s;

bool divisable(int x) {
	cout<<x<<endl;
	cin>>s;
	if(s[0] == 'y') return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif

	int p2[] = {4,9,25,49};
	int p[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};

	int cnt = 0;
	rep(i, 4) cnt += divisable(p2[i]);
	if(cnt>0) {
		cout<<"composite";
		return 0;
	}
	rep(i, 15) cnt += divisable(p[i]);
	if(cnt>1) cout<<"composite";
	else cout<<"prime";
}