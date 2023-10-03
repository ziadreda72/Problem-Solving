#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MAX = (int) 1e6;

int cnt[MAX + 1];

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N;
        cin >> N;

        for(int i = 0 ; i < N ; ++i){
                int x;
                cin >> x;
                ++cnt[x];
        }

        if(cnt[1]){
                cout << (cnt[1] == 1 ? 1 : 0);
                return 0;
        }

        vector < int > a;
        for(int i = 2 ; i <= MAX ; ++i){
                if(cnt[i] == 0) continue;
                a.push_back(i);
        }

        N = (int) a.size();
        vector < bool > dp(N , 1);
        
        for(int i = 0 ; i < N ; ++i){
                if(cnt[a[i]] > 1) dp[i] = 0;

                for(int j = 2 * a[i] ; j <= MAX ; j += a[i]){
                        if(binary_search(a.begin() + i + 1 , a.end() , j)){
                                int idx = lower_bound(a.begin() + i + 1 , a.end() , j) - a.begin();
                                dp[idx] = 0;
                        }
                }
        }

        cout << accumulate(dp.begin() , dp.end() , 0);

        return 0;
}
