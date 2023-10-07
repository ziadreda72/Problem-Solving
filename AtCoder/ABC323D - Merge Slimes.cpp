#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N;
        cin >> N;

        map < i64 , i64 > mp;
        for(int i = 0 ; i < N ; ++i){
                i64 S , C;
                cin >> S >> C;
                mp[S] += C;
        }

        i64 ans = 0;
        
        auto it = mp.begin();
        while(it != mp.end()){
                i64 S = (*it).first , C = (*it).second;
                if(C & 1){
                        ans++;
                        C--;
                }
                if(C){
                        mp[S * 2] += C / 2;
                }
                mp.erase(it);
                it = mp.begin();
        }

        cout << ans;

        return 0;
}
