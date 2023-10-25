#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

const int MAX = (int) 1e6;

vector < int > d(MAX , -1);

int LOG10(i64 x){
        int ret = 0;
        while(x){
                ++ret;
                x /= 10;
        }
        return ret;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        i64 a , N;
        cin >> a >> N;

        int A = LOG10(N);

        queue < i64 > q;

        d[1] = 0;
        
        q.push(1);
        while(!q.empty()){
                int x = q.front();
                q.pop();

                if(LOG10(a * x) <= A){
                        if(d[a * x] == -1){
                                d[a * x] = d[x] + 1;
                                q.push(a * x);
                        }
                }

                if(x > 9 && x % 10 != 0){
                        string s = to_string(x);
                        char c = s.back();
                        s.pop_back();
                        s = c + s;
                        auto new_x = stoll(s);

                        if(LOG10(new_x) <= A){
                                if(d[new_x] == -1){
                                        d[new_x] = d[x] + 1;
                                        q.push(new_x);
                                }
                        }
                }
        }

        cout << d[N];

        return 0;
}
