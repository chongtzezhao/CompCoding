// Sample Failed: WA

/*
Last updated: May 18 2020, 00:19

Problem
Carl has an array of N candies. The i-th element of the array (indexed starting from 1) is Ai representing sweetness value of the i-th candy. He would like to perform a series of Q operations. There are two types of operation:
Update the sweetness value of a candy in the array.
Query the sweetness score of a subarray.

The sweetness score of a subarray from index l to r is: Al × 1 - Al+1 × 2 + Al+2 × 3 - Al+3 × 4 + Al+4 × 5 ...

More formally, the sweetness score is the sum of (-1)i-lAi × (i - l + 1), for all i from l to r inclusive.

For example, the sweetness score of:
[3, 1, 6] is 3 × 1 - 1 × 2 + 6 × 3 = 19
[40, 30, 20, 10] is 40 × 1 - 30 × 2 + 20 × 3 - 10 × 4 = 0
[2, 100] is 2 × 1 - 100 × 2 = -198

Carl is interested in finding out the total sum of sweetness scores of all queries. If there is no query operation, the sum is considered to be 0. Can you help Carl find the sum?

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a line containing N and Q. The second line contains N integers describing the array. The i-th integer is Ai. The j-th of the following Q lines describe the j-th operation. Each line begins with a single character describing the type of operation (U for update, Q for query).
For an update operation, two integers Xj and Vj follow, indicating that the Xj-th element of the array is changed to Vj.
For a query operation, two integers Lj and Rj follow, querying the sweetness score of the subarray from the Lj-th element to the Rj-th element (inclusive).

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the total sum of sweetness scores of all the queries.

Limits
Time limit: 20 seconds per test set.
Memory limit: 1GB.
1 ≤ T ≤ 100.
1 ≤ Ai ≤ 100, for all i.
1 ≤ N ≤ 2 × 105 and 1 ≤ Q ≤ 105 for at most 6 test cases.
For the remaining cases, 1 ≤ N ≤ 300 and 1 ≤ Q ≤ 300.
If the j-th operation is an update operation, 1 ≤ Xj ≤ N and 1 ≤ Vj ≤ 100.
If the j-th operation is a query operation, 1 ≤ Lj ≤ Rj ≤ N.

Test set 1
There will be at most 5 update operations.

Test set 2
There are no special constraints.

Sample

Input
 
2
5 4
1 3 9 8 2
Q 2 4
Q 5 5
U 2 10
Q 1 2
3 3
4 5 5
U 1 2
U 1 7
Q 1 2

Output  
  
Case #1: -8
Case #2: -3

  
In sample case #1:
The first query asks for the sweetness score of [3, 9, 8] which is 3 × 1 - 9 × 2 + 8 × 3 = 9.
The second query asks for the sweetness score of [2] which is 2 × 1 = 2.
The third query asks for the sweetness score of [1, 10] which is 1 × 1 - 10 × 2 = -19.
Thus, the final output should be 9 + 2 - 19 = -8.

In sample case #2:
The first and only query asks for the sweetness score of [7, 5] which is 7 × 1 - 5 × 2 = -3.
Thus, the final output should be -3.*/

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
    ll N, Q;
    cin>>N>>Q;
    ll A[N];
    rep(i, 0, N) cin>>A[i];
    ll altsum[N];
    altsum[0] = A[0];
    rep(i, 1, N){
        if(i%2){
            altsum[i]=altsum[i-1]-A[i];
        }
        else{
            altsum[i]=altsum[i-1]+A[i];
        }
    }
    ll upsum[N];
    upsum[0] = A[0];
    rep(i, 1, N){
        if(i%2){
            upsum[i]=upsum[i-1]-A[i]*(i+1);
        }
        else{
            upsum[i]=upsum[i-1]+A[i]*(i+1);
        }
    }
    char c;
    ll a, b;
    set<ll> u;
    ll ans = 0;
    rep(i, 0, Q){
        cin>>c>>a>>b;
        if(c=='Q'){
            bool k = false;
            for(auto it:u){
                if (it>=a && it<=b){
                    k = true;
                }
            }
            if(k){
                ll ad=1;
                for(ll as=a-1;as<b;++as){
                    if(ad%2)ans+=A[as];
                    else ans-=A[as];
                    ++ad;
                }
            }
            else{
                if(a==1)ans+=upsum[b-1];
                else{
                    if (a%2){
                        ans += upsum[b-1]-upsum[a-2]-(a-1)*(altsum[b-1]-altsum[a-2]);
                    }
                    else{
                        ans += (upsum[b-1]-upsum[a-2])*(-1)+(a-1)*(altsum[b-1]-altsum[a-2]);
                    }
                }
            }
        }
        else{
            A[a-1] = b;
            u.insert(a);
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
