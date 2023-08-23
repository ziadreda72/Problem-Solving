#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int N;
        cin >> N;
        i64 ans = 0;
        for(int i = 1 ; i < N ; ++i){
                int CD = i , AB = N - i;
                int cnt = 0 , cnt2 = 0;
                for(int d = 1 ; d * d <= AB ; ++d){
                        if(AB % d == 0){
                                if(d == AB / d)
                                        cnt++;
                                else
                                        cnt += 2;
                        }
                }
                for(int d = 1 ; d * d <= CD ; ++d){
                        if(CD % d == 0){
                                if(d == CD / d)
                                        cnt2++;
                                else
                                        cnt2 += 2;
                        }
                }
                ans += 1LL * cnt * cnt2;
        }
        cout << ans;
        return 0;
}
