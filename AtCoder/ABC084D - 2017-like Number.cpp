#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MAX = (int) 1e6;

bool is_prime[MAX + 1];

void sieve(){
        memset(is_prime , 1 , sizeof is_prime);

        is_prime[0] = is_prime[1] = 0;

        for(int i = 4 ; i <= MAX ; i += 2){
                is_prime[i] = 0;
        }

        for(int i = 3 ; i * i <= MAX ; i += 2){
                if(is_prime[i]){
                        for(int j = i * i ; j <= MAX ; j += i){
                                is_prime[j] = 0;
                        }
                }
        }
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        sieve();

        vector < int > v;
        for(int i = 3 ; i <= (int) 1e5 ; i += 2){
                if(is_prime[i] && is_prime[(i + 1) / 2]){
                        v.push_back(i);
                }
        }

        int Q;
        cin >> Q;

        while(Q--){
                int L , R;
                cin >> L >> R;

                cout << upper_bound(v.begin() , v.end() , R) - lower_bound(v.begin() , v.end() , L) << '\n';
        }

        return 0;
}
