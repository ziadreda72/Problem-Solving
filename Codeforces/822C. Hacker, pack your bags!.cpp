#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

int BS(int l , vector < pair < pair < int , int > , int > > &v){
    int low = -1 , hi = (int) v.size();
    while (hi - low > 1){
        int mid = (low + hi) >> 1;
        if(v[mid].F.S < l){
            low = mid;
        }else{
            hi = mid;
        }
    }
    return low;
}

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    int n , x;
    cin >> n >> x;
    map < int , vector < pair < pair < int , int > , int > > > mp;
    map < pair < int , int > , int > mp2;
    map < int , vector < int > > mp3;
    for (int i = 0; i < n; ++i) {
        int l , r , c;
        cin >> l >> r >> c;
        if(r - l + 1 >= x) continue;
        if(mp2.contains({l , r})) mp2[{l , r}] = min(mp2[{l , r}] , c);
        else mp2[{l , r}] = c;
    }
    for(auto [p , c] : mp2){
        int l = p.F , r = p.S;
        mp[r - l + 1].push_back({{l , r} , c});
    }
    for(auto & [_ , v] : mp){
        sort(v.begin(), v.end());
        for (int i = 0; i < (int) v.size(); ++i) {
            if(i == 0) mp3[_].push_back(v[i].S);
            else mp3[_].push_back(min(mp3[_].back() , v[i].S));
        }
    }
    int ans = INT32_MAX;
    for(auto [y , v] : mp){
        int z = x - y;
        if(z <= 0) continue;
        for(auto p : v){
            int l = p.F.F , r = p.F.S , c = p.S;
            int i = BS(l , mp[z]);
            if(i == -1) continue;
            ans = min(ans , mp3[z][i] + c);
        }
    }
    ans = ans == INT32_MAX ? -1 : ans;
    cout << ans;
    return 0;
}
