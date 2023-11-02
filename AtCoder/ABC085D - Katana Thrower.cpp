#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N , H;
        cin >> N >> H;

        vector < int > b;

        int a = INT32_MIN;

        for(int i = 0 ; i < N ; ++i){
                int x , y;
                cin >> x >> y;

                b.push_back(y);

                a = max(a , x);        
        }

        sort(b.begin() , b.end());

        int ans = 0;

        while(!b.empty()){
                if(H > 0 && b.back() >= a){
                        H -= b.back();
                        b.pop_back();
                        ans++;
                }else break;
        }

        if(H > 0){
                ans += (H + a - 1) / a;
        }

        cout << ans;

        return 0;
}
