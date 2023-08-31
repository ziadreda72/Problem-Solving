#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

void solveTC(){
        int n , k;
        cin >> n >> k;
        vector < int > a(n);
        set < int > st;
        for(int i = 0 ; i < n ; ++i){
                cin >> a[i];
                st.insert(a[i]);
        }
        int mod = n + 1;
        if(k % mod == 0){
                for(auto x : a){
                        cout << x << ' ';
                }
                return;
        }
        int mex = 0;
        for(auto x : st){
                if(mex != x){
                        break;
                }
                ++mex;
        }
        vector < int > v;
        v.push_back(mex);
        for(int i = 0 ; i < n ; ++i){
                swap(mex , a[i]);
                v.push_back(mex);
        }
        int x = k % mod - 1;
        int i = (0 - x + mod) % mod;
        while(n--){
                cout << v[i] << ' ';
                i = (i + 1) % mod;
        }
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int tc;
        cin >> tc;
        while (tc--){
                solveTC();
                cout << '\n';
        }
        return 0;
}
