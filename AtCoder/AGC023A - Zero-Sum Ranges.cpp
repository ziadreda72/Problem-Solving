#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N;
        cin >> N;

        map < i64 , int > mp;
        mp[0] = 1;
        i64 S = 0 , ans = 0;
        for(int i = 0 ; i < N ; ++i){
                int x;
                cin >> x;
                S += x;
                ans += mp[S]++;
        }

        cout << ans;

        return 0;
}
