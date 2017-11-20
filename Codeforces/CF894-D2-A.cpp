#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)
#define repn(i,k,n) for(int i=(int)(k); i<=(int)(n); ++i)
#define repi(i,k,n) for(int i=(int)(k); i<(int)(n); ++i)
#define X first
#define Y second
#define PB push_back


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);    
    #ifndef ONLINE_JUDGE
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
    #endif
    string str;
    cin>>str;
    int q = str.size();
    int cnt = 0;
    rep(i, q-2) {
       repi(j,i+1, q-1) {
            repi(k, j+1, q) {
                if(str[i]=='Q' && str[j] =='A' && str[k]=='Q') ++cnt;
            }
       }
    }
    cout<<cnt;
}