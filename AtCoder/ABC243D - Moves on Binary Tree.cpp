#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N;
        cin >> N;

        i64 X;
        cin >> X;

        string s;
        cin >> s;

        vector < bool > v;
        for(auto c : s){
                if(c == 'U'){
                        if(v.empty()) X /= 2;
                        else v.pop_back();
                }else{
                        v.push_back(c == 'L' ? 0 : 1);
                }
        }

        for(auto x : v) X = 2 * X + x;

        cout << X;

        return 0;
}
