#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

int getMin(int n , vector < pair < int , int > > v , vector < pair < int , int > > v2){
        v.pop_back();
        int ret = (n >> 1) - (v.empty() ? 0 : v.back().F);
        ret += (n >> 1) - (v2.empty() ? 0 : v2.back().F);
        return ret;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n;
        cin >> n;
        vector < int > a(n);
        int mx = -1;
        for(int i = 0 ; i < n ; ++i){
                cin >> a[i];
                mx = max(mx , a[i]);
        }
        vector < int > cnt(mx + 5 , 0);
        vector < pair < int , int > > v , v2;
        for(int i = 0 ; i < n ; i += 2){
                cnt[a[i]]++;
        }
        for(int i = 1 ; i <= mx ; ++i){
                if(cnt[i] == 0){
                        continue;
                }
                v.emplace_back(cnt[i] , i);
        }
        fill(cnt.begin() , cnt.end() , 0);
        for(int i = 1 ; i < n ; i += 2){
                cnt[a[i]]++;
        }
        for(int i = 1 ; i <= mx ; ++i){
                if(cnt[i] == 0){
                        continue;
                }
                v2.emplace_back(cnt[i] , i);
        }
        sort(v.begin() , v.end());
        sort(v2.begin() , v2.end());
        if(v.back().S != v2.back().S){
                int ans = (n >> 1) - v.back().F;
                ans += (n >> 1) - v2.back().F;
                cout << ans;
        }else{
                cout << min(getMin(n , v , v2) , getMin(n , v2 , v));
        }
        return 0;
}
