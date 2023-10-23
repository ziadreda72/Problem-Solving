#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N;
        cin >> N;

        string s;
        cin >> s;

        vector < int > v;
        for(auto c : s){
                if(c == 'R') v.push_back(0);
                if(c == 'G') v.push_back(1);
                if(c == 'B') v.push_back(2);
        }

        vector suf(3 , vector < int > (N , 0));
        for(int i = 0 ; i < 3 ; ++i){
                for(int j = N - 1 ; j >= 0 ; --j){
                        if(j == N - 1) suf[i][j] = v[j] == i;
                        else suf[i][j] = suf[i][j + 1] + (v[j] == i);
                }
        }

        i64 ans = 0;
        for(int jmp = 1 ; jmp <= N - 2 ; ++jmp){
                for(int i = 0 ; i < N && i + jmp <= N - 2 ; ++i){
                        int j = i + jmp;
                        if(v[i] == v[j]) continue;
                        set < int > st = {0 , 1 , 2};
                        st.erase(v[i]);
                        st.erase(v[j]);
                        int left = *st.begin();
                        ans += suf[left][j + 1] - (j + jmp < N && v[j + jmp] == left);
                }
        }

        cout << ans;

        return 0;
}
