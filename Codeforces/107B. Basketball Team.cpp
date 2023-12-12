#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

ld C(int n , int r){
        if(n < r) return 0.0;

        ld ret = 1.0;
        for(int i = 1 ; i <= n ; ++i){
                ret *= i;
                if(i <= r) ret /= i;
                if(i <= n - r) ret /= i;
        }

        return ret;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int n , m , h;
        cin >> n >> m >> h;
        --h , --n;

        int S = 0;

        vector < int > a(m);
        for(int i = 0 ; i < m ; ++i){
                cin >> a[i];
                if(i != h) S += a[i]; 
        }

        --a[h];

        if(S + a[h] < n){
                cout << -1;
                return 0;
        }

        ld A = C(S , n) , B = C(S + a[h] , n);

        ld P = 1.0 - (A / B);

        cout << fixed << setprecision(20) << P;

        return 0;
}
