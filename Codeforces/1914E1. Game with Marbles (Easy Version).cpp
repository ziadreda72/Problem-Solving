#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MAX = 10;

i64 n , a[MAX] , b[MAX];

i64 solve(int t) {
        bool ended = 1;
        for(int i = 0 ; i < n ; ++i) ended &= a[i] == 0 || b[i] == 0;
        if(ended) {
                i64 A = 0 , B = 0;
                for(int i = 0 ; i < n ; ++i) A += a[i] , B += b[i];
                return A - B;
        }

        i64 ret;

        if(t == 0) {
                ret = INT64_MIN;
                for(int i = 0 ; i < n ; ++i) {
                        if(a[i] > 0 && b[i] > 0) {
                                a[i]--;
                                int x = b[i];
                                b[i] = 0;
                                ret = max(ret , solve(1));
                                a[i]++;
                                b[i] = x;
                        }
                }
                return ret;
        }else {
                ret = INT64_MAX;
                for(int i = 0 ; i < n ; ++i) {
                        if(a[i] > 0 && b[i] > 0) {
                                b[i]--;
                                int x = a[i];
                                a[i] = 0;
                                ret = min(ret , solve(0));
                                b[i]++;
                                a[i] = x;
                        }
                }
                return ret;
        }

}

void solveTC(){
        cin >> n;

        for(int i = 0 ; i < n ; ++i) cin >> a[i];
        for(int j = 0 ; j < n ; ++j) cin >> b[j];

        cout << solve(0);
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
