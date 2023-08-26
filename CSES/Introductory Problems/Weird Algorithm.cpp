
#include <bits/stdc++.h>
 
using namespace std;
using i64 = long long;
using ld = long double;
 
#define F first
#define S second
 
int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        i64 n;
        cin >> n;
        cout << n;
        while(n != 1){
                if(n % 2 == 0)
                        n /= 2;
                else
                        n = (n * 3) + 1;
                cout << ' ' << n;
        }
        return 0;
}
