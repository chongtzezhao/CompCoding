// Full solulution

/*
Last updated: May 18 2020, 00:25

Problem
Avery has an array of N positive integers. The i-th integer of the array is Ai.

A contiguous subarray is an m-countdown if it is of length m and contains the integers m, m-1, m-2, ..., 2, 1 in that order. For example, [3, 2, 1] is a 3-countdown.

Can you help Avery count the number of K-countdowns in her array?

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a line containing the integers N and K. The second line contains N integers. The i-th integer is Ai.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the number of K-countdowns in her array.

Limits
Time limit: 20 seconds per test set.
Memory limit: 1GB.
1 ≤ T ≤ 100.
2 ≤ K ≤ N.
1 ≤ Ai ≤ 2 × 105, for all i.

Test set 1
2 ≤ N ≤ 1000.

Test set 2
2 ≤ N ≤ 2 × 105 for at most 10 test cases.
For the remaining cases, 2 ≤ N ≤ 1000.

Sample

Input
 	
Output
 
3
12 3
1 2 3 7 9 3 2 1 8 3 2 1
4 2
101 100 99 98
9 6
100 7 6 5 4 3 2 1 100

  
Case #1: 2
Case #2: 0
Case #3: 1

  
In sample case #1, there are two 3-countdowns as highlighted below.
1 2 3 7 9 3 2 1 8 3 2 1
1 2 3 7 9 3 2 1 8 3 2 1

In sample case #2, there are no 2-countdowns.

In sample case #3, there is one 6-countdown as highlighted below.
100 7 6 5 4 3 2 1 100
*/

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
