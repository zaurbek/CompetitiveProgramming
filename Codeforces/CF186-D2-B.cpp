#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef pair<int,double> id;
typedef vector<id> vid;
#define REP(i,n) for(int i=0; i<(int)(n); ++i)

bool f(const id &a, const id &b) {
    if(a.second==b.second) return a.first<b.first;
    return a.second>b.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,t1,t2,k;
    cin>>n>>t1>>t2>>k;
    vid v1;
    REP(i, n) {
        int a,b;
        cin>>a>>b;
        double res1 = (t1*a)*(1-k/100.0) + b*t2;
        double res2 = (t1*b)*(1-k/100.0) + a*t2;
        v1.push_back({i+1, max(res1,res2)});
    }
    sort(v1.begin(), v1.end(), f);
    REP(i, v1.size()) {
        printf("%d %.2f\n",v1[i].first, v1[i].second);
    }
}
