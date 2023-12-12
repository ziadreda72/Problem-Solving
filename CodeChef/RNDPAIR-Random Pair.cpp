#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solveTC(){
        int N;
        cin >> N;

        vector < int > a(N);
        for(int i = 0 ; i < N ; ++i) cin >> a[i];

        map < int , int > mp;
        for(int i = 0 ; i < N ; ++i) for(int j = i + 1 ; j < N ; ++j) mp[a[i] + a[j]]++;

        int x = (*mp.rbegin()).second;
        int y = N * (N - 1) / 2;

        cout << fixed << setprecision(8);

        long double ans = (long double) x / y;

        cout << ans;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int tc;
        cin >> tc;
        
        while (tc--){
                solveTC();
                cout << '\n';
        }
        
        return 0;
}
