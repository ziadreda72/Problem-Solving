#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MAX = (int) 2e5 + 5;

int N;
int a[MAX];
vector < int > par , sz;

void make_set(int v){
        par[v] = v;
        sz[v] = 1;
}

int find_set(int v){
        return par[v] == v ? v : find_set(par[v]);
}

void union_sets(int a , int b){
        a = find_set(a);
        b = find_set(b);

        if(a != b){
                if(sz[a] < sz[b]){
                        swap(a , b);
                }
                par[b] = a;
                sz[a] += sz[b];
        }
}


int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        cin >> N;
        
        int mx = -1;
        for(int i = 0 ; i < N ; ++i){
                cin >> a[i];
                mx = max(mx , a[i]--);
        }

        par.resize(mx);
        sz.resize(mx);

        for(int i = 0 ; i < mx ; ++i){
                make_set(i);
        }

        for(int i = 0 ; i < N ; ++i){
                if(a[i] != a[N - i - 1]){
                        union_sets(a[i] , a[N - i - 1]);
                }
        }

        set < int > roots;
        for(int i = 0 ; i < mx ; ++i){
                roots.insert(find_set(i));
        }

        int ans = 0;
        for(auto x : roots){
                ans += sz[x] - 1;
        }

        cout << ans;

        return 0;
}
