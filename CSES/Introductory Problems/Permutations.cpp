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
        if(n == 1){
                cout << 1;
                return 0;
        }
        if(n <= 3){
                cout << "NO SOLUTION";
                return 0;
        }
        for(int i = 2 ; i <= n ; i += 2){
                cout << i << ' ';
        }
        for(int i = 1 ; i <= n ; i += 2){
                cout << i << ' ';
        }
        return 0;
}
