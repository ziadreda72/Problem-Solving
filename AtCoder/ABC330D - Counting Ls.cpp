#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N;
        cin >> N;

        vector < string > s(N);
        for(int i = 0 ; i < N ; ++i) cin >> s[i];

        vector < int > row(N) , col(N);

        for(int i = 0 ; i < N ; ++i){
                for(int j = 0 ; j < N ; ++j){
                        if(s[i][j] == 'o') ++row[i] , ++col[j];
                }
        }

        i64 ans = 0;

        for(int i = 0 ; i < N ; ++i){
                for(int j = 0 ; j < N ; ++j){
                        if(s[i][j] == 'o'){
                                ans += 1LL * (row[i] - 1) * (col[j] - 1);
                        }
                }
        }

        cout << ans;

        return 0;
}
