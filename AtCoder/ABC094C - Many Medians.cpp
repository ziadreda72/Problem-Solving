#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N;
        cin >> N;

        vector < array < int , 2 > > a(N);
        for(int i = 0 ; i < N ; ++i){
                cin >> a[i][0];
                a[i][1] = i;
        }

        sort(a.begin() , a.end());

        vector < int > ans(N);

        for(int i = 0 ; i < N ; ++i){
                if(i < N / 2){
                        ans[a[i][1]] = a[N / 2][0];
                }else{
                        ans[a[i][1]] = a[N / 2 - 1][0];
                }
        }

        for(auto x : ans) cout << x << '\n';

        return 0;
}
