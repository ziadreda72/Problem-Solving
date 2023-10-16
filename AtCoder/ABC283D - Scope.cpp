#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        string s;
        cin >> s;

        set < char > S;
        stack < set < char > > stk;

        for(auto c : s){
                if(c == '('){
                        set < char > new_S;
                        stk.push(new_S);
                }
                
                else if(c == ')'){
                        auto cur = stk.top();
                        stk.pop();
                        for(auto x : cur) S.erase(x);
                }

                else{
                        if(S.count(c)){
                                cout << "No";
                                return 0;
                        }
                        if(stk.size()){
                                stk.top().insert(c);
                        }
                        S.insert(c);
                }
        }

        cout << "Yes";

        return 0;
}
