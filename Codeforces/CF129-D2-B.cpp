#inlcude <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<n; ++i)
typedef vector<int> vi;

// some sublime testing

bool g[6000][6000] = {};

int m,n;

vector<pair<int,int>> check() {
    vector<pair<int,int>> qwe;
    REP(i, m) {
        int sum = 0, last;
        REP(j, m) {
            if(g[i][j]) {
                    ++sum;
                    last = j;

            }
        }
        if(sum==1) qwe.push_back({i,last});
    }
    return qwe;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);    
    #ifndef ONLINE_JUDGE
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
    #endif
    cin>>m>>n;
    REP(i,n) {
        int a,b;
        cin>>a>>b;
        g[a-1][b-1] = true;
        g[b-1][a-1] = true;
    }
    int cnt = 0;
    vector<pair<int,int>> lol;
    do {
        lol = check();
        if(!lol.empty()) ++cnt;
        REP(i, lol.size()) {
            g[lol[i].first][lol[i].second] = false;
            g[lol[i].second][lol[i].first] = false;
        }
    } while(!lol.empty());
    cout<<cnt;
}