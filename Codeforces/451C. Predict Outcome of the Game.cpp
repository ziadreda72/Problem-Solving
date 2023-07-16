#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool solve(i64 n , i64 k , i64 x , i64 y){
        i64 t = k + y - x;
        if(t < 0 || t % 3)
                return 0;
        i64 b = t / 3 , a = b + x , c = b - y;
        bool ok = 1;
        for(auto i : {a , b , c})
                ok &= i >= 0 && i <= n / 3;
        return ok;
}

void solveTC() {
        i64 n , k , d1 , d2;
        cin >> n >> k >> d1 >> d2;
        if(n % 3){
                cout << "no";
                return;
        }
        for(auto i : {-d1 , d1})
                for(auto j : {-d2 , d2})
                        if(solve(n , k , i , j)){
                                cout << "yes";
                                return;
                        }
        cout << "no";
}

int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int tc = 1;
        cin >> tc;
        while(tc--){
                solveTC();
                cout << '\n';
        }
        return 0;
}
