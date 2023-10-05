#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        string s;
        cin >> s;
        int sz = (int) s.size();

        i64 cur = 0;
        for(int i = 0 ; i < sz ; ++i){
                if(s[i] == '1') cur += 1LL << (sz - i - 1);
        }

        i64 N;
        cin >> N;

        if(cur > N){
                cout << -1;
                return 0;
        }

        for(int i = 0 ; i < sz ; ++i){
                if(s[i] == '?' && cur + (1LL << (sz - i - 1)) <= N){
                        cur += (1LL << (sz - i - 1));
                }
        }

        cout << cur;

        return 0;
}
