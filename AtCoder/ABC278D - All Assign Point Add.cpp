#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N;
        cin >> N;

        map < int , i64 > mp;
        for(int i = 0 ; i < N ; ++i){
                i64 x;
                cin >> x;
                mp[i] = x;
        }

        int Q;
        cin >> Q;

        i64 lst = -1;

        while(Q--){
                int t;
                cin >> t;

                if(t == 1){
                        i64 x;
                        cin >> x;

                        mp.clear();
                        lst = x;
                }

                if(t == 2){
                        int i;
                        i64 x;
                        cin >> i >> x;
                        --i;

                        if(mp.count(i)) mp[i] += x;
                        else mp[i] = lst + x;
                }

                if(t == 3){
                        int i;
                        cin >> i;
                        --i;
                        if(mp.count(i)) cout << mp[i] << '\n';
                        else cout << lst << '\n';
                }
        }

        return 0;
}
