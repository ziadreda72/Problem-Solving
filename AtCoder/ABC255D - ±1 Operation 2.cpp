#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n , Q;
        cin >> n >> Q;
        vector < int > a(n);
        for(int i = 0 ; i < n ; ++i){
                cin >> a[i];
        }
        sort(a.begin() , a.end());
        vector < i64 > prf(n , 0LL) , suf(n , 0LL);
        for(int i = 0 ; i < n ; ++i){
                if(i == 0){
                        prf[i] = a[i];
                }else{
                        prf[i] += prf[i - 1] + a[i];
                }
        }
        for(int i = n - 1 ; i >= 0 ; --i){
                if(i == n - 1){
                        suf[i] = a[i];
                }else{
                        suf[i] += suf[i + 1] + a[i];
                }
        }
        while(Q--){
                int x;
                cin >> x;
                int i = upper_bound(a.begin() , a.end() , x) - a.begin();
                int j = n - i;
                i64 ans = ((1LL * x * i) - (i == 0 ? 0 : prf[i - 1])) + ((i == n ? 0 : suf[i]) - (1LL * x * j));
                cout << ans << '\n';
        }
        return 0;
}
