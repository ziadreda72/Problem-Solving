#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        i64 A , B;
        cin >> A >> B;

        i64 ans = 0;

        while(A != B){
                if(A < B){
                        swap(A , B);
                }
                i64 x = ((A + B - 1) / B) - 1;
                ans += x;
                A -= B * x;
        }

        cout << ans;

        return 0;
}
