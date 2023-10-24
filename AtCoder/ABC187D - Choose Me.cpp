#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N;
        cin >> N;

        vector < i64 > a;
        
        i64 X = 0;

        for(int i = 0 ; i < N ; ++i){
                i64 A , B;
                cin >> A >> B;
                a.push_back(A + A + B);
                X -= A;
        }

        sort(a.begin() , a.end());

        int ans = 0;
        while(!a.empty() && X <= 0){
                ans++;
                X += a.back();
                a.pop_back();
        }

        cout << ans;

        return 0;
}
