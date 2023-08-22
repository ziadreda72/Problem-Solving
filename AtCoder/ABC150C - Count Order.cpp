#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using i128 = __int128;
using ld = long double;

#define F first
#define S second

int n;

int get(vector < int > &v){
        int cur = 0;
        vector < int > p(n);
        iota(p.begin() , p.end() , 1);
        do{
                cur++;
                if(p == v)
                        return cur;
        }while(next_permutation(p.begin() , p.end()));
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cin >> n;
        vector < int > p(n) , q(n);
        for(int i = 0 ; i < n ; ++i){
                cin >> p[i];
        }
        for(int i = 0 ; i < n ; ++i){
                cin >> q[i];
        }
        cout << abs(get(p) - get(q));
        return 0;
}
