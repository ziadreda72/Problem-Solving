#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solveTC(){
        int n;
        cin >> n;

        vector < int > a(n);
        for(int i = 0 ; i < n ; ++i) cin >> a[i];

        sort(a.begin() , a.end());

        i64 x = 0 , ans = 0;

        int i = 0 , j = n - 1;
        while(i <= j){
                if(i == j){
                        if(a[i] <= 1) ans += a[i];
                        else ans += (a[i] - x + 1) / 2 + 1;
                        
                        cout << ans;

                        return;
                }

                if(x + a[i] < a[j]){
                        x += a[i];
                        ans += a[i++];
                }else{
                        i64 d = a[j] - x;
                        a[i] -= d;
                        ans += d + 1;
                        x = 0;
                        j--;
                        if(a[i] == 0) i++;
                }
        }

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
