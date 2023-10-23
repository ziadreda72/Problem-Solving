#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        string s;
        cin >> s;

        if(s.size() == 1){
                cout << (stoi(s) % 8 == 0 ? "Yes" : "No");
                return 0;
        }

        if(s.size() == 2){
                if(stoi(s) % 8 == 0){
                        cout << "Yes";
                        return 0;
                }
                swap(s[0] , s[1]);
                cout << (stoi(s) % 8 == 0 ? "Yes" : "No");
                return 0;
        }

        vector < int > cnt(10 , 0);
        for(auto c : s){
                cnt[c - '0']++;
        }

        for(int i = 112 ; i < 1000 ; i += 8){
                auto c = cnt;
                for(auto x : to_string(i)) c[x - '0']--;
                if(all_of(c.begin() , c.end() , [](int x){return x >= 0;})){
                        cout << "Yes";
                        return 0;
                }
        }

        cout << "No";

        return 0;
}
