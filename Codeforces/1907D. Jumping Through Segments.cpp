#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solveTC(){
        int n;
        cin >> n;

        vector < int > l(n) , r(n);
        for(int i = 0 ; i < n ; ++i) cin >> l[i] >> r[i];

        auto good = [&](int k){
                int L = 0 , R = 0;
                
                for(int i = 0 ; i < n ; ++i){
                        L -= k , R += k;
                        L = max(L , l[i]);
                        R = min(R , r[i]);
                        if(L > R){
                                return false;
                        }
                }

                return true;
        };

        int lo = l[0] - 1 , hi = (int) 1e9;
        while(hi - lo > 1){
                int mid = (lo + hi) / 2;
                if(good(mid)){
                        hi = mid;
                }else{
                        lo = mid;
                }
        }

        cout << hi;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int tc;
        cin >> tc;
        
        while (tc--){
                solveTC();
                cout << '\n';
        }
        
        return 0;
}
