#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N;
        cin >> N;

        i64 sum = 0 , mx = 0;
        for(int i = 0 ; i < N ; ++i){
                i64 x;
                cin >> x;

                mx = max(mx , x);
                sum += x;
        }

        if(sum % 2 == 0 && (mx * 2 <= sum)){
                cout << "YES";
        }else{
                cout << "NO";
        }

        return 0;
}
