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

const int nax = 2e4+7;

int a[nax][2];

int main() {
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif

	int n = read();
	ll sum = 0;
	while(n--) {
		int i,j;
		i = read();
		j = read();
		int r1 = i+j;
		int r2 = i-j+1000;
		sum+=a[r1][0];
		sum+=a[r2][1];
		a[r1][0]++;
		a[r2][1]++;
	}
	cout<<sum;
}