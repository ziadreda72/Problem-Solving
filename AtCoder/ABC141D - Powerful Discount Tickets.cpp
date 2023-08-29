#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n , m;
        cin >> n >> m;
        priority_queue < int > pq;
        i64 ans = 0;
        while(n--){
                int x;
                cin >> x;
                ans += x;
                pq.push(x);
        }
        while(m--){
                int x = pq.top();
                pq.pop();
                ans -= x - (x >> 1);
                pq.push(x >> 1);
        }
        cout << ans;
        return 0;
}
