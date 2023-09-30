#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

const int N = (int) 3e5;

vector < bool > is_prime(N + 5 , 1);
vector < i64 > pr;

void sieve(){
        is_prime[0] = is_prime[1] = 0;

        for (int i = 4; i <= N; i += 2) {
                is_prime[i] = 0;
        }

        for (int i = 3; i * i <= N; i += 2) {
                if(is_prime[i]){
                        for (int j = i * i; j <= N; j += i) {
                                is_prime[j] = 0;
                        }
                }
        }

        for(int i = 2 ; i <= N ; ++i){
                if(is_prime[i]) pr.push_back(i);
        }
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        sieve();

        i64 n;
        cin >> n;

        int ans = 0;
        for(int i = 0 ; i < (int) pr.size() ; ++i){
                i64 x = pr[i] * pr[i];
                if(x > n) break;

                for(int j = i + 1 ; j < (int) pr.size() ; ++j){
                        i64 y = x * pr[j];
                        if(y > n) break;

                        for(int k = j + 1 ; k < (int) pr.size() ; ++k){
                                i64 z = y * pr[k];
                                if(z > n) break;
                                z *= pr[k];
                                if(z > n) break;
                                ans++;
                        }
                }
        }

        cout << ans;

        return 0;
}
