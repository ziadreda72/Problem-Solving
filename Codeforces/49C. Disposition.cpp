#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int32_t main() {
        ios::sync_with_stdio(false);cin.tie(nullptr);
        cout.tie(nullptr);cout.precision(20);
        int n;
        cin >> n;
        if(n & 1){
                cout << 1 << ' ';
                int x = 3 , y = 2;
                for (int i = 2; i <= n; ++i) {
                        if(i % 2 == 0){
                                cout << x << ' ';
                                x += 2;
                        }else{
                                cout << y << ' ';
                                y += 2;
                        }
                }
        }else{
                int x = 1 , y = 2;
                for (int i = 0; i < n; ++i) {
                        if(i & 1){
                                cout << x << ' ';
                                x += 2;
                        }else{
                                cout << y << ' ';
                                y += 2;
                        }
                }
        }
        return 0;
}
