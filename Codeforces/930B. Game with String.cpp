#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        string s;
        cin >> s;

        int n = (int) s.size();

        vector v(26 , vector (26 , vector < int > (n , 0)));

        for(int i = 0 ; i < n ; ++i){
                for(int j = 1 ; j < n ; ++j){
                        v[s[0] - 'a'][s[j] - 'a'][j]++;
                }
                rotate(s.begin() , s.begin() + 1 , s.end());
        }

        int ans = 0;

        for(int i = 0 ; i < 26 ; ++i){
                int mx = 0;
                for(int j = 1 ; j < n ; ++j){
                        int cnt = 0;
                        for(int k = 0 ; k < 26 ; ++k){
                                cnt += v[i][k][j] == 1;
                        }
                        mx = max(mx , cnt);
                }
                ans += mx;
        }

        cout << fixed << setprecision(20) << (ld) ans / n;

        return 0;
}
