#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

const int N = (int) 1e6;

vector < int > is_prime(N + 1 , 1) , pr(N + 1 , 0);

void sieve(){
        is_prime[0] = is_prime[1] = 0;
        for(int i = 4 ; i <= N ; i += 2){
                is_prime[i] = 0;
        }
        for(int i = 3 ; i * i <= N ; i += 2){
                if(is_prime[i]){
                        for(int j = i * i ; j < N ; j += i){
                                is_prime[j] = 0;
                        }
                }
        }
        for(int i = 2 ; i <= N ; ++i){
                pr[i] += pr[i - 1] + is_prime[i];
        }
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        sieve();
        i64 n;
        cin >> n;
        int ans = 0;
        for(int i = 2 ; i <= N; ++i){
                if(!is_prime[i]){
                        continue;
                }
                ans += pr[min(1LL * (i - 1) , n / (1LL * i * i * i))];
        }
        cout << ans;
        return 0;
}
