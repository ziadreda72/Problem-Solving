#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

int n;
vector < string > s;
vector < vector < int > > g;
vector < int > deg;
vector < char > color;
int cycle_st;

void kill(){
    cout << "Impossible";
    exit(0);
}

bool dfs(int u){
    color[u] = 1;
    for(auto v : g[u]){
        if(color[v] == 0){
            if(dfs(v))
                return true;
        }else if(color[v] == 1){
            cycle_st = u;
            return true;
        }
    }
    color[u] = 2;
    return false;
}

vector < char > alpha;
vector < char > ans;
vector < bool > vis;

void dfs2(int u){
    vis[u] = 1;
    for(auto v : g[u]){
        if(!vis[v])
            dfs2(v);
    }
    ans.push_back(alpha[u]);
}

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string x;
        cin >> x;
        s.push_back(x);
    }
    g = vector < vector < int > > (26);
    color.assign(26 , 0);
    deg.assign(26 , 0);
    cycle_st = -1;
    for (int i = 0; i + 1 < n; ++i) {
        bool ok = 1;
        for (int j = 0; j < min((int) s[i].size() , (int) s[i + 1].size()); ++j) {
            if(s[i][j] == s[i + 1][j]) continue;
            int u = s[i][j] - 'a';
            int v = s[i + 1][j] - 'a';
            deg[v]++;
            g[u].push_back(v);
            ok = 0;
            break;
        }
        if(ok && s[i].size() > s[i + 1].size())
            kill();
    }
    for (int i = 0; i < 26; ++i) {
        if(color[i] == 0 && deg[i] == 0){
            if(dfs(i)) break;
        }
    }
    for (int i = 0; i < 26; ++i) {
        if(color[i] != 2)
            kill();
    }
    if(cycle_st != -1)
        kill();
    for(char c = 'a' ; c <= 'z' ; c++) alpha.push_back(c);
    vis.assign(26 , 0);
    for (int i = 0; i < 26; ++i) {
        if(!vis[i]) dfs2(i);
    }
    reverse(ans.begin(), ans.end());
    for(auto c : ans) cout << c;
    return 0;
}
