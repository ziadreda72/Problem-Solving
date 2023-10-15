#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N;
        cin >> N;

        vector < int > A(N);
        for(int i = 0 ; i < N ; ++i) cin >> A[i];

        int M;
        cin >> M;

        vector < int > B(M);
        for(int i = 0 ; i < M ; ++i) cin >> B[i];

        int X;
        cin >> X;

        vector < bool > dp(X + 1 , false) , ok(X + 1 , true);

        for(auto x : B) ok[x] = false; 

        dp[0] = 1;
        for(int i = 0 ; i <= X ; ++i){
                if(dp[i] == 0) continue;

                for(auto x : A){
                        if(i + x > X) break;

                        if(!ok[i + x]) continue;

                        dp[i + x] = 1;
                }
        }

        cout << (dp[X] ? "Yes" : "No");

        return 0;
}
