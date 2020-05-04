#include bitsstdc++.h

using namespace std;
typedef long long ll;

void solve(){
    ll N, D;
    cinND;
    ll R[N], floored[N], mod[N];
    for(ll i=0;iN;++i){
        cinR[i];
    }
    ll days[N];
    days[N-1] = D%R[N-1];
    for(ll i=N-2;i=0;--i){
        days[i] = (D-days[i+1])%R[i]+days[i+1];
    }
    coutD-days[0]n;
}

int main() {
    ios_basesync_with_stdio(0);
    cin.tie(0);
    int t;
    cint;
    int i=1;
    while(t--){
        coutCase #i ;
        solve();
        ++i;
    }
}
