#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N , M;
        cin >> N >> M;

        vector < int > A(M);
        for(int i = 0 ; i < M ; ++i) cin >> A[i];

        vector < int > P(N , 0);
        iota(P.begin() , P.end() , 1);

        vector < vector < int > > v(N);
        for(int i = 0 ; i < N ; ++i){
                string s;
                cin >> s;
                for(int j = 0 ; j < M ; ++j){
                        if(s[j] == 'o') P[i] += A[j];
                        else v[i].push_back(A[j]);
                }
                sort(v[i].begin() , v[i].end());
        }

        for(int i = 0 ; i < N ; ++i){
                int cur = P[i] , mx = 0;
                for(int j = 0 ; j < N ; ++j){
                        if(i == j) continue;
                        mx = max(mx , P[j]);
                }
                auto v2 = v[i];
                int ans = 0;
                while(!v2.empty() && cur <= mx){
                        cur += v2.back();
                        v2.pop_back();
                        ans++;
                }
                cout << ans << '\n';
        }

        return 0;
}
