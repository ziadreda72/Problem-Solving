#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const int N = 3005 , P = 998244353;

int add(int x , int y){
        x %= P;
        y %= P;
        return 1LL * (x + y) % P;
}

int n;
string s;
int dp[N][N];

int solve(int i , int x){
        if(i >= n)
                return !x;
        auto &ret = dp[i][x];
        if(ret != -1)
                return ret;
        ret = 0;
        if(s[i] == '?'){
                if(x > 0){
                        ret = add(ret , solve(i + 1 , x - 1));
                }
                ret = add(ret , solve(i + 1 , x + 1));
        }else{
                if(s[i] == '(')
                        ret = add(ret , solve(i + 1 , x + 1));
                else if(x > 0)
                        ret = add(ret , solve(i + 1 , x - 1));
        }
        return ret;
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cin >> s;
        n = (int) s.size();
        memset(dp , -1 , sizeof dp);
        cout << solve(0 , 0);
        return 0;
}
