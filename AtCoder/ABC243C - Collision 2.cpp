#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using i128 = __int128;
using ld = long double;

#define F first
#define S second

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n;
        cin >> n;
        vector < pair < int , int > > v(n);
        for(int i = 0 ; i < n ; ++i){
                cin >> v[i].F >> v[i].S;
        }
        string s;
        cin >> s;
        map < int , vector < pair < int , char > > > mp;
        for(int i = 0 ; i < n ; ++i){
                mp[v[i].S].emplace_back(v[i].F , s[i]);
        }
        bool ans = 0;
        for(auto [key , val] : mp){
                sort(val.begin() , val.end());
                bool right = 0;
                for(int i = 0 ; i < val.size() ; ++i){
                     if(val[i].S == 'R')
                             right = 1;
                     else{
                             if(right)
                                     ans = 1;
                     }
                }
        }
        cout << (ans ? "Yes" : "No");
        return 0;
}
