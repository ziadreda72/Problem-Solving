#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

const int INF = INT_MAX;

int SQRT(int x){
        int lo = 0 , hi = 400;
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
        int n;
        cin >> n;
        int SQ = SQRT(n);
        vector < int > a(n) , b(SQ , INF);
        for(int i = 0 ; i < n ; ++i){
                cin >> a[i];
                int k = i / SQ;
                b[k] = min(b[k] , a[i]);
        }
        int Q;
        cin >> Q;
        for(int q = 0 ; q < Q ; ++q){
                int l , r;
                cin >> l >> r;
                int ans = INF;
                for(int i = l ; i <= r ;){
                        if(i % SQ == 0 && i + SQ - 1 <= r){
                                ans = min(ans , b[i / SQ]);
                                i += SQ;
                        }else{
                                ans = min(ans , a[i++]);
                        }
                }
                cout << ans << '\n';
        }
        return 0;
}
