#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int T;
    cin>>T;
    int N, B, c, num;
    multiset<int> costs;
    for (int t=0;t<T;++t){
        cin>>N>>B;
        costs.clear();
        for(int i=0;i<N;++i){
            cin>>c;
            costs.insert(c);
        }
        num = 0;
        for (auto it : costs){
            if (B - it < 0){
                break;
            }
            B-=it;
            ++num;
        }
        cout<<"Case #"<<t+1<<": "<<num<<endl;
    }
}
