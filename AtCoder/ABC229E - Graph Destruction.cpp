#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MAX = (int) 2e5 + 5;

int N , M , cmp;
vector < int > g[MAX];
int par[MAX] , sz[MAX] , dp[MAX];

void make_set(int v){
        par[v] = v;
        sz[v] = 1;
        cmp++;
}

int find_set(int v){
        return par[v] = (par[v] == v ? v : find_set(par[v]));
}

void union_sets(int a , int b){
        a = find_set(a);
        b = find_set(b);

        if(a != b){
                if(sz[a] < sz[b]){
                        swap(a , b);
                }
                sz[a] += sz[b];
                par[b] = a;
                --cmp;
        }
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        cin >> N >> M;

        while(M--){
                int u , v;
                cin >> u >> v;
                g[u].push_back(v);
        }

        dp[N + 1] = 0;
        for(int i = N ; i >= 2 ; --i){
                sort(g[i].begin() , g[i].end());
                make_set(i);
                for(auto j : g[i]){
                        union_sets(i , j);
                }
                dp[i] = cmp;
        }

        for(int i = 2 ; i <= N + 1 ; ++i) cout << dp[i] << '\n';

        return 0;
}
