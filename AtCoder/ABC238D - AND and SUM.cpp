#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

void solveTC(){
        i64 a , s;
        cin >> a >> s;
        i64 x = s - a - a;
        if(x < 0){
          cout << "No";
          return;
        }
        auto ans = x & a;
        cout << (!ans ? "Yes" : "No");
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
