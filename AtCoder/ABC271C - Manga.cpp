#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N;
        cin >> N;

        map < int , int > mp;
        for(int i = 0 ; i < N ; ++i){
                int x;
                cin >> x;
                ++mp[x];
        }

        auto good = [&](int x){
                int can = 0;
                for(auto [key , val] : mp){
                        if(key > x) can += val;
                        else can += val - 1;
                }
        
                can /= 2;
                for(int i = 1 ; i <= x ; ++i){
                        can -= !mp.count(i);
                }

                return can >= 0;
        };

        int lo = 0 , hi = (int) 1e6;
        while(hi - lo > 1){
                int mid = (lo + hi) / 2;
                if(good(mid)){
                        lo = mid;
                }else{
                        hi = mid;
                }
        } 

        cout << lo;

        return 0;
}
