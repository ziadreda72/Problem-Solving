#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MAX = (int) 3e6;

bool is_prime[MAX + 1];

void sieve(){
        is_prime[0] = is_prime[1] = 0;

        for(int i = 4 ; i <= MAX ; i += 2) is_prime[i] = 0;

        for(int i = 3 ; i * i <= MAX ; i += 2){
                if(is_prime[i]){
                        for(int j = i * i ; j <= MAX ; j += i) is_prime[j] = 0;
                }
        }
}

void solveTC(){
        i64 N;
        cin >> N;

        for(int i = 2 ; i <= MAX ; ++i){
                if(is_prime[i]){
                        if((N % i == 0) && ((N / i) % i == 0)){
                                cout << i << ' ' << N / i / i;
                                return;
                        }else if(N % i == 0){
                                cout << (i64) sqrt(N / i) << ' ' << i;
                                return;
                        }
                }
        }
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        for(auto &x : is_prime) x = true;

        sieve();

        int tc;
        cin >> tc;
        
        while (tc--){
                solveTC();
                cout << '\n';
        }
        
        return 0;
}
