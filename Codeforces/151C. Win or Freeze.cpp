#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        i64 n;
        cin >> n;
        if(n == 1){
                cout << "1\n0";
                return 0;
        }
        vector < i64 > divs;
        for(i64 d = 2 ; d * d <= n ; ++d){
                while (n % d == 0){
                        divs.push_back(d);
                        n /= d;
                }
        }
        if(n > 1)
                divs.push_back(n);
        if(divs.size() == 1){
                cout << "1\n0";
        }else if(divs.size() == 2){
                cout << 2;
        }else{
                cout << "1\n" << (1LL * divs[0] * divs[1]);
        }
        return 0;
}
