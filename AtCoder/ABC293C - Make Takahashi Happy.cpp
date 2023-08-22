#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using i128 = __int128;
using ld = long double;

#define F first
#define S second

const int N = 15;
const int dr[] = {0 , 1};
const int dc[] = {1 , 0};

int n , m;
int a[N][N];
map < int , int > mp;
i64 ans;

bool check(int r , int c){
        return (0 <= r && r < n && 0 <= c && c < m);
}

void solve(int r , int c){
        if(r == n - 1 && c == m - 1){
                bool ok = 1;
                for(auto [key , val] : mp)
                        ok &= val <= 1;
                ans += ok;
        }
        for(int i = 0 ; i < 2 ; ++i){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(check(nr , nc)){
                        mp[a[nr][nc]]++;
                        solve(nr , nc);
                        mp[a[nr][nc]]--;
                }
        }
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cin >> n >> m;
        for(int i = 0 ; i < n ; ++i)
                for(int j = 0 ; j < m ; ++j)
                        cin >> a[i][j];
        mp[a[0][0]]++;
        solve(0 , 0);
        cout << ans;
        return 0;
}
