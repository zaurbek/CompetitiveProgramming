#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); ++i)

int main() {
    #ifndef ONLINE_JUDGE
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
    #endif
    string s1,s2;
    cin>>s1>>s2;
    int check = 0;
    REP(i, s1.size()) {
        if(s1[i]=='+') ++check;
        else --check;
    }
    vector<int> res;
    res.push_back(0);
    REP(i, s2.size()) {
        if(s2[i]=='+')
            REP(j,res.size()) ++res[j];
        else if(s2[i]=='-')
            REP(j, res.size()) --res[j];
        else {
            vector<int> ans;
            REP(j, res.size()) {
                ans.push_back(res[j]+1);
                ans.push_back(res[j]-1);
            }
            res = ans;
        }
    }
    int totale = 0;
    REP(i, res.size()) {
        if(res[i]==check) ++totale;
    }
    printf("%.9f", (totale+0.0)/res.size());
}