#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int dr[] = {0 , 0 , -1 , -1 , -1 , 1 , 1 , 1};
const int dc[] = {1 , -1 , -1 , 0 , 1 , -1 , 0 , 1};

int R , C;

bool check(int r , int c){
        return (0 <= r && r < R) && (0 <= c && c < C);
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        cin >> R >> C;

        vector < string > g(R);
        for(int i = 0 ; i < R ; ++i) cin >> g[i];

        for(int i = 0 ; i < R ; ++i){
                for(int j = 0 ; j < C ; ++j){
                        if(g[i][j] == 's'){ 
                                for(int k = 0 ; k < 8 ; ++k){
                                        int ni = i , nj = j;
                                        string s;
                                        s += g[ni][nj];
                                        vector < array < int , 2 > > ans;
                                        ans.push_back({ni + 1 , nj + 1});
                                        for(int l = 0 ; l < 4 ; ++l){
                                                ni += dr[k] , nj += dc[k];
                                                if(check(ni , nj)){
                                                        s += g[ni][nj];
                                                        ans.push_back({ni + 1 , nj + 1});
                                                }else{
                                                        break;
                                                }
                                        }
                                        if(s == "snuke"){
                                                for(auto [r , c] : ans) cout << r << ' ' << c << '\n';
                                                return 0;
                                        }
                                }
                                
                        }
                }
        }

        return 0;
}
