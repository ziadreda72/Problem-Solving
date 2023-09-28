#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        vector < i64 > v;
        for(int msk = 2 ; msk < (1 << 10) ; ++msk){
                i64 num = 0;
                for(int i = 9 ; i >= 0 ; --i){
                        if((msk >> i) & 1){
                                num = num * 10 + i;
                        }
                }
                v.push_back(num);
        }

        sort(v.begin() , v.end());

        int k;
        cin >> k;

        cout << v[k - 1];

        return 0;
}
