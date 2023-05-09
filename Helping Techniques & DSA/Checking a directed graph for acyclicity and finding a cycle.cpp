#include <bits/stdc++.h>

using namespace std;

int n; // # of Vertices
int m; // # of Edges
vector < vector < int > > g; // Adjacency List
vector < char > color; // 0 --> Not-Visited , 1 --> Visited , 2 --> On Exit
vector < int > par; // To keep track the parent of each vertex
int cyc_st; // First vertex in the cycle
int cyc_en; // Last vertex in the cycle

bool dfs(int u){
    color[u] = 1;
    for(auto v : g[u]){
        if(color[v] == 0){
            par[v] = u;
            if(dfs(v))
                return true;
        }else if(color[v] == 1){
            cyc_st = v;
            cyc_en = u;
            return true;
        }
    }
    color[u] = 2;
    return false;
}

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    cin >> n >> m;
    g = vector < vector < int > > (n);
    color.assign(n , 0);
    par.assign(n , -1);
    cyc_st = -1;
    while (m--){
        int u , v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 0; i < n; ++i) {
        if(color[i] == 0 && dfs(i))
            break;
    }
    if(cyc_st == -1){
        cout << "Acyclic Graph\n";
        return 0;
    }
    vector < int > cyc; // To print the cycle
    cyc.push_back(cyc_st);
    for(int v = cyc_en ; v != cyc_st ; v = par[v]){
        cyc.push_back(v);
    }
    cyc.push_back(cyc_st);
    reverse(cyc.begin(), cyc.end());
    cout << "Cycle Found: ";
    for(auto v : cyc) cout << v << ' ';
    cout << '\n';
    return 0;
}
