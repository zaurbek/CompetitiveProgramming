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

	int n = read();
	int dif = 0, a = 0, g = 0;
	string res = "";
	while(n--) {
		int x = read();
		int y = read();
		if(dif + x <= 500) {
			dif += x;
			res+="A";
		} else {
			dif -= y;
			res += "G";
		}
	}
	printf(res);
}