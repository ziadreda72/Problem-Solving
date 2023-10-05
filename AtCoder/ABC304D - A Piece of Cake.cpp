#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int W , H;
        cin >> W >> H;

        int N;
        cin >> N;
        vector < array < int , 2 > > p(N);
        for(int i = 0 ; i < N ; ++i) cin >> p[i][0] >> p[i][1];

        int A;
        cin >> A;
        vector < int > a(A);
        for(int i = 0 ; i < A ; ++i) cin >> a[i];
        a.push_back(W);

        int B;
        cin >> B;
        vector < int > b(B);
        for(int i = 0 ; i < B ; ++i) cin >> b[i];
        b.push_back(H);

        map < array < int , 2 > , int > mp;
        for(auto [x , y] : p){
                int x2 = *upper_bound(a.begin() , a.end() , x);
                int y2 = *upper_bound(b.begin() , b.end() , y);
                mp[{x2 , y2}]++;
        }

        int mn = (int) 1e9 , mx = 0;
        if((i64) mp.size() < 1LL * (A + 1) * (B + 1)) mn = 0;
        for(auto [_ , x] : mp){
                mn = min(mn , x);
                mx = max(mx , x);
        }

        cout << mn << ' ' << mx;

        return 0;
}
