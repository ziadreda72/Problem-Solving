#include <bits/stdc++.h>

using namespace std;

#define int long long

void solveTC() {
        int n , m , h;
        cin >> n >> m >> h;
        vector < pair < pair < int , int > , int > > ans;
        for (int i = 0; i < n; ++i) {
                vector < int > v;
                for (int j = 0; j < m; ++j) {
                        int t;
                        cin >> t;
                        v.push_back(t);
                }
                sort(v.begin(), v.end());
                int tot = 0 , p = 0 , pen = 0;
                for (int j = 0; j < m; ++j) {
                        if(tot + v[j] <= h){
                                p++ , tot += v[j];
                                pen += tot;
                        }
                }
                ans.push_back({{p , pen} , i + 1});
        }
        sort(ans.begin(), ans.end() , [](pair < pair < int , int > , int > &a , pair < pair < int , int > , int > &b){
           if(a.first.first == b.first.first){
                   if(b.first.second == a.first.second)
                           return a.second < b.second;
                   return a.first.second < b.first.second;
           }
                return a.first.first > b.first.first;
        });
        for (int i = 0; i < n; ++i) {
                if(ans[i].second == 1){
                        cout << i + 1;
                        return;
                }
        }
}

int32_t main() {
        ios::sync_with_stdio(false);cin.tie(nullptr);
        cout.tie(nullptr);cout.precision(20);
        int tc = 1;
        cin >> tc;
        while(tc--){
                solveTC();
                cout << '\n';
        }
        return 0;
}
