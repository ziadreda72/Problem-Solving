#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n , m;
        cin >> n >> m;
        vector < pair < int , char > > a;
        while(m--){
                int s;
                char c;
                cin >> s >> c;
                s--;
                a.emplace_back(s , c);
        }
        for(int i = 0 ; i < 1000 ; ++i){
                string s = to_string(i);
                bool ok = (int) s.size() == n;
                for(auto [j , c] : a){
                        ok &= s[j] == c;
                }
                if(ok){
                        cout << i;
                        return 0;
                }
        }
        cout << -1;
        return 0;
}
