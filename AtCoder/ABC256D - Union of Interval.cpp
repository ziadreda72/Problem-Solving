#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        static const int MAX = (int) 2e5;

        int N;
        cin >> N;

        vector < int > par(MAX + 1 , 0);
        while(N--){
                int L , R;
                cin >> L >> R;
                par[L]++;
                par[R]--;
        }

        for(int i = 1 ; i <= MAX ; ++i) par[i] += par[i - 1];

        bool f = false;
        for(int i = 0 ; i <= MAX ; ++i){
                if(!f && par[i]){
                        cout << i << ' ';
                        f = true;
                }else if(f && !par[i]){
                        cout << i << '\n';
                        f = false;
                }
        }

        return 0;
}
