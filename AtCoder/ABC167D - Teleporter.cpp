#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MAX = (int) 2e5 + 10;

int N;
vector < int > g[MAX];
int color[MAX] , par[MAX];
int st , en;
i64 K;

bool dfs(int u){
        if(K == 0){
                cout << u;
                exit(0);
        }

        color[u] = 1;

        for(auto v : g[u]){
                if(color[v] == 0){
                        par[v] = u;
                        K--;
                        if(dfs(v)){
                                return true;
                        }
                }else if(color[v] == 1){
                        st = v;
                        en = u;
                        K--;
                        return true;
                }
        }

        color[u] = 2;
        return false;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        cin >> N >> K;

        for(int i = 1 ; i <= N ; ++i){
                int x;
                cin >> x;
                
                g[i].push_back(x);
        }

        dfs(1);

        vector < int > cycle;
        for(int v = en ; v != st ; v = par[v]) cycle.push_back(v);
        cycle.push_back(st);

        reverse(cycle.begin() , cycle.end());

        N = (int) cycle.size();

        cout << cycle[K % N];

        return 0;
}
