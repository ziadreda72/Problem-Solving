#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        string s , t;
        cin >> s >> t;

        int c = count(t.begin() , t.end() , '?');

        int x = 0;
        for(auto i : s){
                i == '+' ? x++ : x--;
        }

        int y = 0;
        for(auto i : t){
                if(i == '?') continue;
                i == '+' ? y++ : y--;
        }

        int z = 0;

        for(int msk = 0 ; msk < (1 << c) ; ++msk){
                y += __builtin_popcount(msk);
                y -= c - __builtin_popcount(msk);

                z += x == y;

                y -= __builtin_popcount(msk);
                y += c - __builtin_popcount(msk);

        }

        long double ans = (long double) z / (1 << c);

        cout << setprecision(20) << ans;

        return 0;
}
