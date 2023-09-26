#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N , M;
        cin >> N >> M;

        vector < queue < int > > a(M);
        vector < vector < int > > top(N);
        queue < int > q;
        for(int i = 0 ; i < M ; ++i){
                int k;
                cin >> k;
                for(int j = 0 ; j < k ; ++j){
                        int x;
                        cin >> x;
                        a[i].push(--x);
                }
                top[a[i].front()].push_back(i);
        }

        for(int i = 0 ; i < N ; ++i){
                if(top[i].size() == 2) q.push(i);
        }

        while(!q.empty()){
                int cur = q.front();
                q.pop();
                for(auto i : top[cur]){
                        a[i].pop();
                        if(!a[i].empty()){
                                top[a[i].front()].push_back(i);
                                if(top[a[i].front()].size() == 2) q.push(a[i].front());
                        }
                }
        }

        for(auto q2 : a){
                if(!q2.empty()){
                        cout << "No";
                        return 0;
                }
        }

        cout << "Yes";

        return 0;
}
