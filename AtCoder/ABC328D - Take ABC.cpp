#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        string s;
        cin >> s;

        int N = (int) s.size();

        string aux;
        for(int i = 0 ; i < N ;){
                if(s[i] == 'A'){
                        if(i + 2 < N && s.substr(i , 3) == "ABC"){
                                i += 3;
                        }else{
                                aux += s[i];
                                i++;
                        }
                }

                if(s[i] == 'B'){
                        if(aux.empty() || aux.back() != 'A'){
                                aux += s[i];
                                cout << aux;
                                aux.clear();
                                i++;
                        }else{
                                aux += s[i];
                                i++;
                        }
                }

                if(s[i] == 'C'){
                        if(aux.empty() || aux.back() == 'A'){
                                aux += s[i];
                                cout << aux;
                                aux.clear();
                                i++;
                        }else{
                                aux.pop_back();
                                aux.pop_back();
                                i++;
                        }
                }
        }

        if(aux.size()) cout << aux;

        return 0;
}
