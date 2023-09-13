#include "bits/stdc++.h"

using namespace std;

int SQRT(int x){
        int lo = 0 , hi = 1;

        while(hi * hi <= x) hi *= 2;

        while(hi - lo > 1){
                int mid = (lo + hi) >> 1;
                if(mid * mid >= x){
                        hi = mid;
                }else{
                        lo = mid;
                }
        }
        return hi;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n , Q;
        cin >> n >> Q;

        int SQ = SQRT(n);
        vector < int > a(n);
        vector < vector < int > > b(SQ);
        for(int i = 0 ; i < n ; ++i){
                cin >> a[i];
                b[i / SQ].push_back(a[i]);
        }
        for(auto &v : b){
                sort(v.begin() , v.end());
        }

        for(int q = 0 ; q < Q ; ++q){
                char c;
                cin >> c;
                if(c == 'C'){
                        int l , r , x;
                        cin >> l >> r >> x;
                        l-- , r--;
                        int ans = 0;
                        for(int i = l ; i <= r ;){
                                if(i % SQ == 0 && i + SQ - 1 <= r){
                                        int k = i / SQ;
                                        ans += upper_bound(b[k].begin() , b[k].end() , x) - b[k].begin();
                                        i += SQ;
                                }else{
                                        ans += a[i] <= x;
                                        i++;
                                }
                        }
                        cout << ans << '\n';
                }else{
                        int i , x;
                        cin >> i >> x;
                        i--;
                        a[i] = x;
                        int k = i / SQ;
                        b[k].clear();
                        for(int i = k * SQ ; i < (k + 1) * SQ ; ++i){
                                b[k].push_back(a[i]);
                        }
                        sort(b[k].begin() , b[k].end());
                }
        }
        
        return 0;
}
