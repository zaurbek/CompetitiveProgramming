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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))

inline int read() {
    int ret=0,c,f=1;
    for(c=getchar(); !(isdigit(c)||c=='-'); c=getchar());
    if(c=='-') f=-1,c=getchar();
    for(; isdigit(c); c=getchar()) ret=ret*10+c-'0';
    if(f<0) ret=-ret;
    return ret;
}

const int nax = 2e5+7;

map<int,int> a;
ii g[nax];
int max_B = -1, pos = 1, n, m, maxi = -1, x;

int main() {
    n = read();
    while(n--) ++a[read()];
    m = read();
    rer(i,1, m) g[i].X = read();
    rer(i,1, m) {
        g[i].Y = read();
        if(a[g[i].X] > maxi) {
            maxi = a[g[i].X];
            max_B = a[g[i].Y];
            pos = i;
        } else if (a[g[i].X] == maxi && a[g[i].Y] > max_B) {
            max_B = a[g[i].Y];
            pos = i;
        }
    }
    cout<<pos;
}