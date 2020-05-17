// Full solulution

#include <bits/stdc++.h>
using namespace std;

// BEGIN NO SAD
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;

void solve(){
    ll N, K;
    cin>>N>>K;
    ll A[N];
    rep(i, 0, N) cin>>A[i];
    if (K>N){
        cout<<0;
        return;
    }
    ll ans=0;
    bool counting;
    rep(i, 0, N){
        if (A[i]==K){
            counting = true;
        }
        else if (counting && A[i]!=A[i-1]-1){
            counting = false;
        }
        if (counting && A[i]==1){
            ++ans;
            counting = false;
        }
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll T;
    cin>>T;
    ll i=0;
    while (T--){
        ++i;
        cout<<"Case #"<<i<<": ";
        solve();
    }


    return 0;
}
