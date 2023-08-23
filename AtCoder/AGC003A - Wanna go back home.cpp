#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using i128 = __int128;
using ld = long double;

#define F first
#define S second

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        string str;
        cin >> str;
        bool n = 0 , w = 0 , s = 0 , e = 0;
        for(auto c : str){
                n |= c == 'N';
                w |= c == 'W';
                s |= c == 'S';
                e |= c == 'E';

        }
        cout << (!((n ^ s) || (e ^ w)) ? "Yes" : "No");
        return 0;
}
