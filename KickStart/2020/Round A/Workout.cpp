#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(ll N, ll K, multiset<ll, greater <ll> > M){
    ll difficulty = *M.begin();
    for(ll i=0;i<K;++i){
        if(difficulty==1) break;
        M.erase(M.begin());
        M.insert(difficulty/2);
        if(difficulty%2==1){
            M.insert(difficulty/2+1);
        }
        else{
            M.insert(difficulty/2);
        }
        difficulty = *M.begin();
    }
    return difficulty;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll T;
    cin>>T;
    ll N, K, m, pm;
    multiset<ll, greater <ll> > M;
    for (ll t=0;t<T;++t){
        M.clear();
        cin>>N>>K;
        for(ll i=0;i<N;++i){
            cin>>m;
            if(i>0) M.insert(m-pm);
            pm=m;
        }
        cout<<"Case #"<<t+1<<": "<<solve(N, K, M)<<endl;
    }
}
