#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        i64 L , N , N2;
        cin >> L >> N >> N2;

        vector < array < i64 , 2 > > A(N) , A2(N2);
        for(int i = 0 ; i < N ; ++i) cin >> A[i][0] >> A[i][1];
        for(int i = 0 ; i < N2 ; ++i) cin >> A2[i][0] >> A2[i][1];

        i64 ans = 0;
        for(int i = 0 , j = 0 ; i < N && j < N2 ;){
                i64 mn = min(A[i][1] , A2[j][1]);

                if(A[i][0] == A2[j][0])
                        ans += mn;
                
                A[i][1] -= mn;
                if(A[i][1] == 0) i++;

                A2[j][1] -= mn;
                if(A2[j][1] == 0) j++;
        }

        cout << ans;

        return 0;
}
