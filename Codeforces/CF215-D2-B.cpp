#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); ++i)
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);    
    #ifndef ONLINE_JUDGE
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
    #endif
    int a,b, c, nMax = -1, kMin = 5000; 
    long long llN, llK;
    double mn;
    cin>>a;
    REP(i, a) {
        int x;
        cin>>x;
        nMax = max(nMax, x);
    }
    
    cin>>b;
    int m[b];
    REP(i,b) cin>>m[i];
    
    cin>>c; 
    REP(i,c) {
        int x;
        cin>>x;
        kMin = min(kMin, x);
    }
    
    llK = kMin;
    llN = nMax;
    cin>>cA>>cB;
    REP(j,b) {
        double res = ((m[j]*1.0*llN*llN))/(cA/cB*llK+m[j]);
        mn = max(mn, res);
    }
    printf("%.12f",sqrt(mn));
}