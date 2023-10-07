#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MOD = 998244353;

int add(int a , int b){
        a %= MOD;
        b %= MOD;
        return 1LL * (a + b) % MOD;
}

int sub(int a , int b){
        a %= MOD;
        b %= MOD;
        return (a - b + MOD) % MOD;
}

int mul(int a , int b){
        a %= MOD;
        b %= MOD;
        return 1LL * a * b % MOD;
}

int P(int a , int b){
        int ret = 1;
        while (b){
                if(b & 1){
                        ret = mul(ret , a);
                }
                a = mul(a , a);
                b >>= 1;
        }
        return ret;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int Q;
        cin >> Q;

        int ans = 1 , N = 1;
        
        queue < int > q;
        q.push(1);
        
        while(Q--){
                int t;
                cin >> t;

                if(t == 1){
                        int x;
                        cin >> x;
                        q.push(x);
                        N++;
                        ans = add(mul(ans , 10) , x);
                }
                if(t == 2){
                        ans = sub(ans , mul(q.front() , P(10 , --N)));
                        q.pop();
                }
                if(t == 3){
                        cout << ans % MOD << '\n';
                }
        }

        return 0;
}
