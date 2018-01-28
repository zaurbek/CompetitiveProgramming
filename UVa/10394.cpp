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

const int n = 2e7;

bool sieve[n+1];

void sieve_of() {
	for(int i=2; i*i<=n; ++i) {
		if(sieve[i]) {
			for(int j=i*i; j<=n; j+=i) {
				sieve[j] = false;
			}
		}
	}
}

const int tw = 1e5+6;

int twinsieve[tw];

void twin_sieve() {
	int cnt = 0;
	for(int i=2; i<=n; ++i) {
		if(sieve[i] && sieve[i+2])
			twinsieve[++cnt] = i;
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif

	memset(sieve, true, sizeof sieve);
	sieve[0] = sieve[1] = false;
	sieve_of();
	twin_sieve();
	int q;
	while(cin>>q) {
		cout<<'('<<twinsieve[q]<<", "<<twinsieve[q]+2<<")\n";
	}
}