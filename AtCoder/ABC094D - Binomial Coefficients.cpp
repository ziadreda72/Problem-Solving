#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N;
        cin >> N;

        vector < int > a(N);
        for(int i = 0 ; i < N ; ++i) cin >> a[i];

        sort(a.begin() , a.end());

        cout << a.back() << ' ';

        int dif = INT32_MAX , idx;
        for(int i = 0 ; i + 1 < N ; ++i){
                if(abs((a.back() - a[i]) - a[i]) < dif){
                        idx = i;
                        dif = abs((a.back() - a[i]) - a[i]);
                }
        }

        cout << a[idx];

        return 0;
}
