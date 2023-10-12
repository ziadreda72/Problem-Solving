#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N , Q;
        cin >> N >> Q;

        vector < int > gone(N + 1);

        int ans = 1;

        while(Q--){
                int t;
                cin >> t;

                if(t == 2){
                        int x;
                        cin >> x;
                        gone[x] = 1;
                }

                if(t == 3){
                        while(gone[ans]) ans++;
                        cout << ans << '\n';
                }
        }

        return 0;
}
