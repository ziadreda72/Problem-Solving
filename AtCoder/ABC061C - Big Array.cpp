#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        i64 n , k;
        cin >> n >> k;

        map < int , i64 > mp;
        while(n--){
                int a , b;
                cin >> a >> b;
                mp[a] += b;
        }

        for(auto [a , b] : mp){
                if(k <= b){
                        cout << a;
                        return 0;
                }
                k -= b;
        }

        return 0;
}
