#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n , c , k;
        cin >> n >> c >> k;
        vector < int > a(n);
        for(int i = 0 ; i < n ; ++i){
                cin >> a[i];
        }
        sort(a.begin() , a.end());
        int ans = 0;
        for(int i = 0 ; i < n ;){
                int j = upper_bound(a.begin() + i , a.end() , a[i] + k) - a.begin() - 1;
                j = min(j , i + c - 1);
                ans++;
                i = j + 1;
        }
        cout << ans;
        return 0;
}
