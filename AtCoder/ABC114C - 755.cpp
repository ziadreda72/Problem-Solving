#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

vector < int > v;

void build(int i , int x , int msk) {
        if(msk == 7) v.push_back(x);

        if (i == 9) return;

        for (auto d : {7 , 5 , 3}) {
                int new_msk = msk;
                if(d == 7) new_msk |= 1 << 2;
                if(d == 5) new_msk |= 1 << 1;
                if(d == 3) new_msk |= 1 << 0;

                x = x * 10 + d;
                build(i + 1 , x , new_msk);
                x /= 10;
        }
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        build(0 , 0 , 0);

        int N;
        cin >> N;

        int ans = 0;

        for (auto x : v) {
                ans += x <= N;
        }

        cout << ans;

        return 0;
}
