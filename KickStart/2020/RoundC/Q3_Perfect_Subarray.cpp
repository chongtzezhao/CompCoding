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

bool isSquare(ll x)
{
  // Find floating point value of
  // square root of x.
  if(x<0) return false;
  long double sr = sqrt(x);

  // If square root is an integer
  return ((sr - floor(sr)) == 0);
}

void solve(){
    ll N;
    cin>>N;
    ll A[N], runsum[N];
    rep(i, 0, N) cin>>A[i];
    runsum[0] = A[0];
    rep(i, 1, N){
        runsum[i] = runsum[i-1]+A[i];
    }
    //rep(i, 0, N) cout<<runsum[i]<<' ';
    //cout<<"\n";
    ll ans=0;
    rep(j, 0, N){
        rep(i, -1, j){
            ll num;
            if (i==-1) num = runsum[j];
            else num = runsum[j]-runsum[i];
            if (isSquare(num) ){
                ++ans;
                //cout<<num<<' ';
            }
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
