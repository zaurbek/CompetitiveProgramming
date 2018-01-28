#include <iostream>

using namespace std;

int main() {
    int a,b,c;
    cin>>a>>b;
    int sum = 0;
    for(int i=0; i<a; ++i) {
        cin>>c;
        if(c>b) sum+=2;
        else sum++;
    }
    cout<<sum;
}