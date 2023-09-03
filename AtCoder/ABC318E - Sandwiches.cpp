#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n;
        cin >> n;
        vector < vector < int > > pos(n + 1);
        for(int i = 0 ; i < n ; ++i){
                int x;
                cin >> x;
                pos[x].push_back(i);
        }
        i64 ans = 0;
        for(int i = 1 ; i <= n ; ++i){
                i64 s = 0;
                for(int j = 0 ; j + 1 < (int) pos[i].size() ; ++j){
                        i64 x = pos[i][j + 1] - pos[i][j] - 1;
                        s += 1LL * (j + 1) * x;
                        ans += s;
                }
        }
        cout << ans;
        return 0;
}
