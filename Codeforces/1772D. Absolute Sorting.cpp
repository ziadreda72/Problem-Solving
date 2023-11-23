#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int INF = INT32_MAX;

void solveTC(){

        int n;
        cin >> n;

        vector < int > a(n);
        for(int i = 0 ; i < n ; ++i) cin >> a[i];

        int lx = 0 , rx = INF;

        for(int i = 0 ; i + 1 < n ; ++i){
                if(a[i] == a[i + 1]) continue;

                if(a[i] < a[i + 1]){
                        int lo = a[i] , hi = a[i + 1];
                        while(hi - lo > 1){
                                int mid = (lo + hi) / 2;
                                if(abs(a[i] - mid) <= abs(a[i + 1] - mid)){
                                        lo = mid;
                                }else{
                                        hi = mid;
                                }
                        }
                        rx = min(rx , lo);
                }

                if(a[i] > a[i + 1]){
                        int lo = a[i + 1] , hi = a[i];
                        while(hi - lo > 1){
                                int mid = (lo + hi) / 2;
                                if(abs(a[i] - mid) <= abs(a[i + 1] - mid)){
                                        hi = mid;
                                }else{
                                        lo = mid;
                                }
                        }
                        lx = max(lx , hi);
                }
        }

        cout << (lx > rx ? -1 : lx); 
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
