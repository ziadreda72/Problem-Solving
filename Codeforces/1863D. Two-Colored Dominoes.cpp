#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

void solveTC(){
        int n , m;
        cin >> n >> m;
        vector < string > g(n);
        for(int i = 0 ; i < n ; ++i){
                cin >> g[i];
        }
        bool ok = 1;
        for(int i = 0 ; i + 1 < n ; ++i){
                vector < int > pos;
                for(int j = 0 ; j < m ; ++j){
                        if(g[i][j] == 'U'){
                                pos.push_back(j);
                        }
                }
                ok &= (pos.size() % 2 == 0);
                for(int k = 0 ; k < pos.size() ; ++k){
                        int j = pos[k];
                        if(k & 1){
                                g[i][j] = 'W';
                                g[i + 1][j] = 'B';
                        }else{
                                g[i][j] = 'B';
                                g[i + 1][j] = 'W';
                        }
                }
        }
        for(int j = 0 ; j + 1 < m ; ++j){
                vector < int > pos;
                for(int i = 0 ; i < n ; ++i){
                        if(g[i][j] == 'L'){
                                pos.push_back(i);
                        }
                }
                ok &= (pos.size() % 2 == 0);
                for(int k = 0 ; k < pos.size() ; ++k){
                        int i = pos[k];
                        if(k & 1){
                                g[i][j] = 'W';
                                g[i][j + 1] = 'B';
                        }else{
                                g[i][j] = 'B';
                                g[i][j + 1] = 'W';
                        }
                }
        }
        if(ok){
                for(auto s : g){
                        cout << s << '\n';
                }
        }
        else{
                cout << "-1\n";
        }
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int tc;
        cin >> tc;
        while (tc--){
                solveTC();
        }
        return 0;
}
