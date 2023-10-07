#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N;
        cin >> N;

        auto ask = [&](int x){
                cout << "? " << x << endl;
                char s;
                cin >> s;
                return s;
        };

        int lo = 0 , hi = N + 1;
        while(hi - lo > 1){
                int mid = (lo + hi) / 2;
                char s = ask(mid);
                if(s == '0'){
                        lo = mid;
                }else{
                        hi = mid;
                }
        }

        cout << "! " << lo << endl;

        return 0;
}
