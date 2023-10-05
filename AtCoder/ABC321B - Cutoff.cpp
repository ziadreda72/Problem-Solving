#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N , X;
        cin >> N >> X;

        vector < int > A(N - 1);
        for(int i = 0 ; i < N - 1 ; ++i) cin >> A[i];

        int sum = accumulate(A.begin() , A.end() , 0);

        for(int i = 0 ; i <= 100 ; ++i){
                int mn = i , mx = i;
                sum += i;
                for(auto x : A){
                        mn = min(mn , x);
                        mx = max(mx , x);
                }
                if(sum - mn - mx >= X){
                        cout << i;
                        return 0;
                }
                sum -= i;
        }
        
        cout << -1;

        return 0;
}
