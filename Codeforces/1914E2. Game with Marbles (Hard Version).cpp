#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solveTC(){
        int n;
        cin >> n;

        vector < int > a(n);
        for(int i = 0 ; i < n ; ++i) cin >> a[i];

        vector < int > b(n);
        for(int i = 0 ; i < n ; ++i) cin >> b[i];

        vector < int > p(n);
        iota(p.begin() , p.end() , 0);
        sort(p.begin() , p.end() , [&](int i , int j){
                return a[i] + b[i] > a[j] + b[j];
        });

        i64 ans = 0;
        for(int i = 0 ; i < n ; ++i) {
                int j = p[i];
                if(i % 2 == 0) {
                        ans += a[j] - 1;
                } else {
                        ans -= b[j] - 1;
                }
        }

        cout << ans;
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
