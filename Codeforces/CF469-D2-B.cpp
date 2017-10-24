#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); ++i)

bool aR[1001] = {};
bool bR[1001] = {};
int main() {
    #ifndef ONLINE_JUDGE
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
    #endif
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    while(a--) {
        int x,y;
        cin>>x>>y;
        for(int i=x; i<=y; ++i) aR[i]=true;
    }
    while(b--) {
        int x,y;
        cin>>x>>y;
        for(int i=x; i<=y; ++i) bR[i]=true;
    }

    int res = 0;
    for(int i=c; i<=d; ++i) {
        bool go  =false;
        REP(j, 1001) {
            int k = j-i;
            if(k>=0 && aR[j] && bR[k]) {
                go = true;
                break;
            }
        }
        if(go) ++res;
    }
    cout<<res;
}