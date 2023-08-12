#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

struct query{
        int t , x;
        char c;
        query(){}
        query(int t , int x , char c): t(t) , x(x) , c(c){}
};

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n , Q;
        string s;
        cin >> n >> s >> Q;
        vector < query > q(Q);
        for (int i = 0; i < Q; ++i) {
                cin >> q[i].t >> q[i].x >> q[i].c;
                q[i].x--;
        }
        bool ok2 = false , ok3 = false;
        vector < bool > vis(n);
        deque < query > dq;
        while (!q.empty()){
                int t = q.back().t , x = q.back().x;
                char c = q.back().c;
                q.pop_back();
                if(t == 2 && !ok2)
                        dq.emplace_front(t , x , c) , ok2 = true;
                if(t == 3 && !ok3)
                        dq.emplace_front(t , x , c) , ok3 = true;
                if(t == 1 && !vis[x])
                        dq.emplace_front(t , x , c) , vis[x] = 1;
        }
        for(auto i : dq){
                int t = i.t , x = i.x;
                char c = i.c;
                if(t == 1)
                        s[x] = c;
                if(t == 2)
                        for(auto &j : s)
                                j = tolower(j);
                if(t == 3)
                        for(auto &j : s)
                                j = toupper(j);
        }
        cout << s;
        return 0;
}
