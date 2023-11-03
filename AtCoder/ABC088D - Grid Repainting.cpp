#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        const int INF = (int) 1e9;
        const int di[] = {0 , 0 , -1 , 1};
        const int dj[] = {-1 , 1 , 0 , 0};

        int N , M;
        cin >> N >> M;

        vector < string > g(N);

        int c = 0;

        for(int i = 0 ; i < N ; ++i){
                cin >> g[i];

                c += count(g[i].begin() , g[i].end() , '#');
        }

        auto check = [&](int i , int j){
                return (0 <= i && i < N) && (0 <= j && j < M) && g[i][j] != '#';
        };

        vector d(N , vector < int > (M , INF));
        d[0][0] = 0;

        queue < array < int , 2 > > q;
        q.push({0 , 0});

        while(!q.empty()){
                int i = q.front()[0] , j = q.front()[1];
                q.pop();

                for(int k = 0 ; k < 4 ; ++k){
                        int ni = i + di[k];
                        int nj = j + dj[k];
                        if(check(ni , nj) && d[i][j] + 1 < d[ni][nj]){
                                d[ni][nj] = d[i][j] + 1;
                                q.push({ni , nj});
                        }
                }
        }

        if(d[N - 1][M - 1] == INF){
                cout << -1;
                return 0;
        }

        cout << (N * M) - c - d[N - 1][M - 1] - 1;

        return 0;
}
