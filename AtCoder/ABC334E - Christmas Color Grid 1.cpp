#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MOD = 998244353;
const int di[] = {0 , 0 , -1 , 1};
const int dj[] = {-1 , 1 , 0 , 0};

int n , m;
vector < string > g;
vector < vector < int > > a;
int cc = 0 , r;

bool check(int i , int j) {
        return (0 <= i && i < n) && (0 <= j && j < m) && a[i][j] == -1 && g[i][j] == '#';
}

bool check2(int i , int j) {
        return (0 <= i && i < n) && (0 <= j && j < m) && g[i][j] == '#';
}

void dfs(int i , int j) {
        a[i][j] = cc;
        for (int k = 0 ; k < 4 ; ++k) {
                int ni = i + di[k];
                int nj = j + dj[k];
                if (check(ni , nj)) {
                        dfs(ni , nj);
                }
        }
}

i64 add(i64 a , i64 b){
        return (1LL * ((a % MOD) + (b % MOD))) % MOD;
}
 
i64 mul(i64 a , i64 b){
        return (1LL * ((a % MOD) * (b % MOD))) % MOD;
}
 
i64 POW(i64 a , i64 b){
        i64 ret = 1;
        while(b){
                if(b & 1)
                        ret = (ret * a) % MOD;
                a = (a * a) % MOD;
                b >>= 1;
        }
        return ret;
}
 
i64 mod_inv(i64 a){
        return POW(a , MOD - 2);
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        cin >> n >> m;

        g.resize(n);
        for (int i = 0 ; i < n ; ++i) {
                cin >> g[i];
                r += count(g[i].begin() , g[i].end() , '.');
        }

        a.assign(n , vector < int > (m , -1));

        for (int i = 0 ; i < n ; ++i) {
                for (int j = 0 ; j < m ; ++j) {
                        if(g[i][j] == '#' && a[i][j] == -1) {
                                dfs(i , j);
                                ++cc;
                        }
                }
        }

        int X = 0;

        for (int i = 0 ; i < n ; ++i) {
                for (int j = 0 ; j < m ; ++j) {
                        if (g[i][j] == '.') {
                                set < int > st;
                                for (int k = 0 ; k < 4 ; ++k) {
                                        if (check2(i + di[k] , j + dj[k])) {
                                                st.insert(a[i + di[k]][j + dj[k]]);
                                        }
                                }
                                if (st.empty()) {
                                        X = add(X , cc + 1);
                                } else {
                                        X = add(X , cc - (st.size() - 1));
                                }
                        }
                }
        }

        cout << mul(X , mod_inv(r));

        return 0;
}
