#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

void solveTC(){
        int n , k;
        cin >> n >> k;

        vector < array < int , 2 > > a(n);
        for(int i = 0 ; i < n ; ++i){
                cin >> a[i][0];
                a[i][0]--;
                a[i][1] = i;
        }
        sort(a.begin() , a.end());

        vector < array < int , 2 > > suf(n);
        for(int i = n - 1 ; i >= 0 ; --i){
                if(i == n - 1){
                        suf[i][0] = suf[i][1] = a[i][1];
                }else{
                        suf[i][0] = max(suf[i + 1][0] , a[i][1]);
                        suf[i][1] = min(suf[i + 1][1] , a[i][1]);
                }
        }

        vector < i64 > ans(k , 0LL);
        for(int i = 0 ; i < n ;){
                ans[a[i][0]] = 2LL * (suf[i][0] - suf[i][1] + 1);
                int j = i;
                while(j < n && a[i][0] == a[j][0]) j++;
                i = j;
        }
        
        for(auto x : ans) cout << x << ' ';
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
