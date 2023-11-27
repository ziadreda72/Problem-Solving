#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int H , W;
        cin >> H >> W;

        int N;
        cin >> N;

        vector < int > a(N);
        for(int i = 0 ; i < N ; ++i) cin >> a[i];

        vector ans(H , vector < int > (W));

        int t = 1 , i = 0 , j = 0 , k = 0;
        while(i < H){
                ans[i][j] = k + 1;
                --a[k];
                if((t == 1 && j == W - 1) || (t == -1 && j == 0)){
                        t *= -1;
                        ++i;
                }else j += t;
                if(!a[k]) ++k;
        }

        for(auto v : ans){
                for(auto x : v) cout << x << ' ';
                cout << '\n'; 
        }

        return 0;
}
