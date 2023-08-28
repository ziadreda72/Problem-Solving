#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n;
        cin >> n;
        vector < int > a(n);
        for(int i = 0 ; i < n ; ++i)
                cin >> a[i];
        int ans = INT_MAX;
        for(int msk = 0 ; msk < (1 << n) ; ++msk){
                int x = a[0] , mn = -1;
                for(int i = 1 ; i < n ; ++i){
                        if(((msk >> i) & 1) == ((msk >> (i - 1)) & 1))
                                x |= a[i];
                        else{
                                if(mn == -1)
                                        mn = x;
                                else
                                        mn ^= x;
                                x = a[i];
                        }
                }
                if(mn == -1)
                        mn = x;
                else
                        mn ^= x;
                ans = min(ans , mn);
        }
        cout << ans;
        return 0;
}
