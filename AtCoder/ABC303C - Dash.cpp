#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n , m , h , k;
        string s;
        cin >> n >> m >> h >> k >> s;
        set < pair < int , int > > st;
        while (m--){
                int x , y;
                cin >> x >> y;
                st.emplace(x , y);
        }
        int curX = 0 , curY = 0;
        for (int i = 0; i < n; ++i) {
                if(s[i] == 'R'){
                        curX++;
                }
                else if(s[i] == 'L'){
                        curX--;
                }
                else if(s[i] == 'U'){
                        curY++;
                }
                else{
                        curY--;
                }
                h--;
                if(h < 0){
                        cout << "No";
                        return 0;
                }
                if(st.find({curX , curY}) != st.end() && h < k){
                        st.erase(st.find({curX , curY}));
                        h = k;
                }
        }
        cout << "Yes";
        return 0;
}
