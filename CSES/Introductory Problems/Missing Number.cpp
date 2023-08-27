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
        vector < int > a(n - 1);
        for(int i = 0 ; i + 1 < n ; ++i)
                cin >> a[i];
        int cur = 1;
        sort(a.begin() , a.end());
        for(int x : a){
                if(x != cur){
                        cout << cur;
                        return 0;
                }
                cur++;
        }
        cout << cur;
        return 0;
}
