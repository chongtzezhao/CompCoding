#include <bits/stdc++.h>

using namespace std;

/*bool compare(string x, string y){
    if(x.length()>y.length()) return true;
    else if(x.length()<y.length()) return false;
    else{
        for(int i=0;i<x.length();++i){
            stringstream geek(x[i]);
            int k = 0;
            geek >> k;
            stringstream geekd(y[i]);
            int j = 0;
            geekd >> j;
            if(k>j) return true;
            else if(k<j) return false;
        }
    }
}*/

void solve(){
    long long n;
    cin>>n;
    long long heights[n];
    for(long long i=0;i<n;++i){
        cin>>heights[i];
    }
    long long total = 0;
    for(long long  i=1;i<n-1;++i){
        if (heights[i]>heights[i-1] && heights[i]>heights[i+1]){
            ++total;
        }
    }
    cout<<total<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    int i=1;
    while(t--){
        cout<<"Case #"<<i<<": ";
        solve();
        ++i;
    }
}
