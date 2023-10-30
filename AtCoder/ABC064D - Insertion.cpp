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

        int x = 0 , y = 0;

        for(int i = 0 ; i < N ; ++i){
                if(s[i] == '(') x++;
                else{
                        if(x){
                                x--;
                        }else{
                                y++;
                        }
                }
        }

        cout << string(y , '(') << s << string(x , ')');

        return 0;
}
