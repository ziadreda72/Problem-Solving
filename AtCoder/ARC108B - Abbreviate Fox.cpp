#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        const string fox = "fox";

        int N;
        cin >> N;

        string s;
        cin >> s;

        int ans = N;

        string tmp;
        for(int i = 0 ; i < N ;){
                if(fox.find(s[i]) == string::npos){
                        tmp.clear();
                        ++i;
                        continue;
                }

                if(s[i] == 'f'){
                        if(i + 2 < N && s.substr(i , 3) == fox){
                                ans -= 3;
                                i += 3;
                        }else{
                                tmp.push_back(s[i]);
                                ++i;
                        }
                        continue;
                }

                if(s[i] == 'o'){
                        if(tmp.back() == 'f'){
                                tmp.push_back(s[i]);
                        }else{
                                tmp.clear();

                        }
                        ++i;
                        continue;
                }

                if(s[i] == 'x'){
                        if(tmp.back() == 'o'){
                                ans -= 3;
                                tmp.pop_back();
                                tmp.pop_back();
                        }else{
                                tmp.clear();
                        }
                        ++i;
                        continue;
                }
        }

        cout << ans;

        return 0;
}
