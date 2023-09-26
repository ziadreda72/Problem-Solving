#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        i64 N;
        cin >> N;

        string ans;
        while(N){
                if(N & 1){
                        ans.push_back('A');
                        N--;
                }else{
                        if(N == 2){
                                ans.push_back('A');
                                N--;
                        }else{
                                ans.push_back('B');
                                N >>= 1;
                        }
                }
        }

        reverse(ans.begin() , ans.end());
        cout << ans;

        return 0;
}
