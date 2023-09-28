#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

const int N = (int) 2e5 + 5;

int n , m , k , q;
vector < int > par(N) , sz(N);

void make_set(int v){
        par[v] = v;
        sz[v] = 1;
}

int find_set(int v){
        return par[v] = (par[v] == v ? v : find_set(par[v]));
}

bool union_sets(int a , int b){
        a = find_set(a);
        b = find_set(b);

        if(a != b){
                if(sz[a] < sz[b]){
                        swap(a , b);
                }
                sz[a] += sz[b];
                par[b] = a;
                return true;
        }
        return false;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        cin >> n >> m;
        for(int i = 1 ; i <= n ; ++i){
                make_set(i);
        }

        while(m--){
                int u , v;
                cin >> u >> v;
                union_sets(u , v);
        }

        for(int i = 1 ; i <= n ; ++i){
                find_set(i);
        }

        cin >> k;
        set < pair < int , int > > st;
        while(k--){
                int u , v;
                cin >> u >> v;

                int x = find_set(u) , y = find_set(v);
                if(x > y) swap(x , y);
                st.emplace(x , y);
        }

        cin >> q;
        while(q--){
                int u , v;
                cin >> u >> v;

                int x = find_set(u) , y = find_set(v);
                if(x > y) swap(x , y);
                
                if(st.find({x , y}) == st.end()){
                        cout << "Yes\n";
                }else{
                        cout << "No\n";
                }
        }

        return 0;
}
