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
        set < pair < int , int > > st;
        vector < int > dr , dc;
        for(int x = 0 ; x < n ; ++x){
                int yy = m - (x * x);
                int y = (int) sqrt(yy);
                if(y * y == yy && (0 <= y && y < n)){
                        st.insert({x , y});
                        st.insert({y , x});
                }
        }
        for(auto [x , y] : st){
                for(int i : {-x , x}){
                        for(int j : {-y , y})
                                dr.push_back(i) , dc.push_back(j);
                }
        }
        vector < vector < int > > d(n + 5 , vector < int > (n + 5 , -1));
        queue < pair < int , int > > q;
        q.emplace(1 , 1);
        d[1][1] = 0;
        while(!q.empty()){
                int r = q.front().F , c = q.front().S;
                q.pop();
                for(int i = 0 ; i < (int) dr.size() ; ++i){
                        int nr = r + dr[i];
                        int nc = c + dc[i];
                        if((1 <= nr && nr <= n) && (1 <= nc && nc <= n)){
                                if(d[nr][nc] == -1){
                                        d[nr][nc] = d[r][c] + 1;
                                        q.emplace(nr , nc);
                                }
                        }
                }
        }
        for(int i = 1 ; i <= n ; ++i){
                for(int j = 1 ; j <= n ; ++j)
                        cout << d[i][j] << ' ';
                cout << '\n';
        }
        return 0;
}
