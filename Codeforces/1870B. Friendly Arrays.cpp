#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

void solveTC(){
        int n , m;
        cin >> n >> m;

        vector < int > a(n);
        for(int i = 0 ; i < n ; ++i) cin >> a[i];

        int OR = 0;
        while(m--){
                int x;
                cin >> x;
                OR |= x;
        }

        int mn = 0 , mx = 0;
        for(auto x : a){
                mn ^= x;
                x |= OR;
                mx ^= x;
        }

        if(n % 2 == 0){
                swap(mn , mx);
        }

        cout << mn << ' ' << mx;
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
