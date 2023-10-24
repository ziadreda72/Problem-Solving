#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N , M;
        cin >> N >> M;

        set < int > divs;
        for(int i = 0 ; i < N ; ++i){
                int x;
                cin >> x;

                for(int d = 2 ; d * d <= x ; ++d){
                        if(x % d == 0){
                                divs.insert(d);
                                while(x % d == 0) x /= d;
                        }
                }

                if(x > 1) divs.insert(x);
        }       

        vector < int > ans;
        for(int i = 1 ; i <= M ; ++i){
                int x = i;

                bool ok = true;
                for(int d = 2 ; d * d <= x ; ++d){
                        if(x % d == 0){
                                if(divs.count(d)){
                                        ok = false;
                                        break;
                                }
                                while(x % d == 0) x /= d;
                        }
                }

                if(!ok){
                        continue;
                }

                if(x > 1) ok &= !divs.count(x);

                if(ok){
                        ans.push_back(i);
                }
        }

        cout << ans.size() << '\n';
        for(auto x : ans) cout << x << '\n';

        return 0;
}
