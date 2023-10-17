#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        const int dx[] = {-1 , -1 , 0 , 0 , 1 , 1};
        const int dy[] = {-1 , 0 , -1 , 1 , 0 , 1};

        int N;
        cin >> N;

        vector < int > x(N) , y(N);
        set < array < int , 2 > > st;

        for(int i = 0 ; i < N ; ++i){
                cin >> x[i] >> y[i];
                st.insert({x[i] , y[i]});
        }

        set < array < int , 2 > > vis;

        int ans = 0;
        for(int i = 0 ; i < N ; ++i){
                if(!vis.count({x[i] , y[i]})){
                        queue < array < int , 2 > > q;
                        q.push({x[i] , y[i]});
                        vis.insert({x[i] , y[i]});
                        ans++;
                        while(!q.empty()){
                                auto cur = q.front();
                                q.pop();
                                int cur_x = cur[0] , cur_y = cur[1];
                                for(int j = 0 ; j < 6 ; ++j){
                                        int new_x = cur_x + dx[j];
                                        int new_y = cur_y + dy[j];
                                        if(st.count({new_x , new_y}) && !vis.count({new_x , new_y})){
                                                q.push({new_x , new_y});
                                                vis.insert({new_x , new_y});
                                        }
                                }
                        }
                }
        }

        cout << ans;

        return 0;
}
