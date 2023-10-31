#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        const int MOD = (int) 1e9 + 7;

        int N;
        cin >> N;

        string s[2];
        cin >> s[0] >> s[1];

        i64 ans;

        int i , lst;

        if(s[0][0] == s[1][0]){
                ans = 3;
                i = 1;
                lst = 0;
        }else{
                ans = 6;
                i = 2;
                lst = 1;
        }

        for(; i < N ;){
                if(s[0][i] == s[1][i]){
                        if(!lst){
                                ans *= 2;
                                ans %= MOD;
                        }
                        lst = 0;
                        i++;
                }else{
                        if(lst){
                                ans *= 3;
                        }else{
                                ans *= 2;
                        }
                        ans %= MOD;
                        lst = 1;
                        i += 2;
                }
        }

        cout << ans;

        return 0;
}
