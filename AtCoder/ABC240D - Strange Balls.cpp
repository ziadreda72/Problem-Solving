#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N;
        cin >> N;

        vector < int > a(N);
        for(int i = 0 ; i < N ; ++i) cin >> a[i];

        stack < array < int , 2 > > s;
        s.push({a[0] , 1});

        int cur = 1;
        cout << cur << '\n';

        for(int i = 1 ; i < N ; ++i){
                cur++;
                if(!s.empty() && a[i] == s.top()[0]){
                        s.top()[1]++;
                        if(s.top()[0] == s.top()[1]){
                                cur -= s.top()[1];
                                s.pop();
                        }
                }else{
                        s.push({a[i] , 1});
                }
                cout << cur << '\n';
        }

        return 0;
}
