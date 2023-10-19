#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N , M;
        cin >> N >> M;

        vector < int > a(M);
        for(int i = 0 ; i < M ; ++i){
                int c;
                cin >> c;
                for(int j = 0 ; j < c ; ++j){
                        int x;
                        cin >> x;
                        --x;
                        a[i] |= 1 << x;
                }
        }

        int ans = 0;
        for(int msk = 1 ; msk < (1 << M) ; ++msk){
                int x = 0;
                for(int i = 0 ; i < M ; ++i){
                        if((msk >> i) & 1){
                                x |= a[i];
                        }
                }
                ans += (x + 1) == (1 << N);
        }

        cout << ans;

        return 0;
}
