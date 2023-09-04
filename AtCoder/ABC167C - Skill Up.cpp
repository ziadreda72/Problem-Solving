#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n , m , x;
        cin >> n >> m >> x;
        vector < pair < int , vector < int > > > a(n);
        for(int i = 0 ; i < n ; ++i){
                cin >> a[i].F;
                for(int j = 0 ; j < m ; ++j){
                        int x;
                        cin >> x;
                        a[i].S.push_back(x);
                }
        }
        int ans = INT32_MAX;
        for(int msk = 0 ; msk < (1 << n) ; ++msk){
                vector < int > v(m , 0);
                int c = 0;
                for(int i = 0 ; i < n ; ++i){
                        if((msk >> i) & 1){
                                c += a[i].F;
                                for(int j = 0 ; j < m ; ++j){
                                        v[j] += a[i].S[j];
                                }
                        }
                }
                bool ok = 1;
                for(auto i : v) ok &= i >= x;
                if(ok){
                        ans = min(ans , c);
                } 
        }
        cout << (ans < INT32_MAX ? ans : -1);
        return 0;
}
