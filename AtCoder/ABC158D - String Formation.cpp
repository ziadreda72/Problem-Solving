#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        string s;
        cin >> s;

        deque < char > q;
        for(auto c : s) q.push_back(c);

        int Q;
        cin >> Q;

        int rev = 0;

        while(Q--){
                int t;
                cin >> t;

                if(t == 1){
                        rev ^= 1;
                }

                if(t == 2){
                        int f;
                        char c;
                        cin >> f >> c;

                        if(f == 1){
                                rev ? q.push_back(c) : q.push_front(c);
                        }else{
                                rev ? q.push_front(c) : q.push_back(c);
                        }
                }
        }

        if(rev) reverse(q.begin() , q.end());

        for(auto c : q) cout << c;

        return 0;
}
