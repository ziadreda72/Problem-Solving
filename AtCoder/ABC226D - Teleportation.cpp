#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N;
        cin >> N;

        vector < int > x(N) , y(N);
        for(int i = 0 ; i < N ; ++i){
                cin >> x[i] >> y[i];
        }

        set < pair < int , int > > s;
        for(int i = 0 ; i < N ; ++i){
                for(int j = 0 ; j < N ; ++j){
                        if(i == j) continue;
                        int dx = x[i] - x[j];
                        int dy = y[i] - y[j];
                        int g = gcd(dx , dy);
                        dx /= g , dy /= g;
                        s.insert({dx , dy});
                }
        }

        cout << s.size();

        return 0;
}
