#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

vector < vector < int > > g(200005);
vector < int > color(200005);
bool ans = false;

bool dfs(int u){
        color[u] = 1;

        for(auto v : g[u]){
                if(color[v] == 0){
                        if(dfs(v)){
                                return true;
                        }
                }else if(color[v] == 1){
                        return true;
                }
        }

        color[u] = 2;

        return false;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N;
        cin >> N;

        int v = 1;
        map < string , int > mp;

        while(N--){
                string a , b;
                cin >> a >> b;

                if(mp.count(a) == 0) mp[a] = v++;
                if(mp.count(b) == 0) mp[b] = v++;

                g[mp[a]].push_back(mp[b]);
        }

        for(int i = 1 ; i < v ; ++i){
                if(color[i] == 0) ans |= dfs(i);
        }

        cout << (ans ? "No" : "Yes");

        return 0;
}
