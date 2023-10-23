#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        queue < i64 > q;
        for(int i = 1 ; i < 10 ; ++i) q.push(i);

        int k;
        cin >> k;

        for(int i = 0 ; i + 1 < k ; ++i){
                auto x = q.front();
                q.pop();

                int d = x % 10;

                if(d - 1 >= 0) q.push(x * 10 + (d - 1));
                q.push(x * 10 + d);
                if(d + 1 <= 9) q.push(x * 10 + (d + 1));
        }

        cout << q.front();

        return 0;
}
