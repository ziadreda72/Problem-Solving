#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

class MessageMess{
private:
    int n;
    string s;
    set < string > st;
    i64 dp[55];
    vector < string > ans;

    i64 solve(int i){
        if(i == n) return 1;
        i64 &ret = dp[i];
        if(ret != -1) return ret;
        ret = 0;
        string s2 = "";
        for (int j = i; j < n; ++j) {
            s2 += s[j];
            if(st.find(s2) != st.end()){
                i64 x = solve(j + 1);
                ret += x;
                if(x == 1) ans.push_back(s2);
            }
        }
        return ret;
    }

public:
    string restore(vector <string> dictionary, string message){
        ans.clear();
        st.clear();
        s = message;
        n = (int) message.size();
        for(auto i : dictionary) st.insert(i);
        memset(dp , -1 , sizeof dp);
        i64 sol = solve(0);
        if(sol == 1){
            reverse(ans.begin(), ans.end());
            string ret = "";
            for (int i = 0; i < (int) ans.size(); ++i) {
                ret += ans[i];
                if(i != (int) ans.size() - 1) ret += ' ';
            }
            return ret;
        }
        return (sol > 1 ? "AMBIGUOUS!" : "IMPOSSIBLE!");
    }
};
