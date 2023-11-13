#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        vector < int > a(3);
        for(int i = 0 ; i < 3 ; ++i) cin >> a[i];

        int M = *max_element(a.begin() , a.end());

        while(true){
                int dif = 0;
                for(auto x : a) dif += M - x;

                if(dif % 2 == 0){
                        cout << dif / 2;
                        return 0;
                }

                M++;
        }

        return 0;
}
