#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

const int N = (int) 2e5 + 5;

int par[N] , sz[N] , deg[N];
int cmp;

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
                if(sz[a] < sz[b])
                        swap(a , b);
                sz[a] += sz[b];
                par[b] = a;
                cmp--;
        }
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n , m;
        cin >> n >> m;
        bool ans = 1;
        ans &= (m == n - 1);
        for(int i = 1 ; i <= n ; ++i)
                make_set(i);
        while(m--){
                int u , v;
                cin >> u >> v;
                deg[u]++;
                deg[v]++;
                union_sets(u , v);
        }
        ans &= (cmp == 1);
        for(int i = 1 ; i <= n ; ++i)
                ans &= (deg[i] <= 2);
        cout << (ans ? "Yes" : "No");
        return 0;
}
