#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N , Q;
        cin >> N >> Q;

        vector < int > r(N + 1 , 0) , f(N + 1 , 0);

        while(Q--){
                int t;
                cin >> t;

                if(t == 1){
                        int x , y;
                        cin >> x >> y;

                        r[x] = y;
                        f[y] = x;
                }

                if(t == 2){
                        int x , y;
                        cin >> x >> y;

                        r[x] = f[y] = 0;
                }

                if(t == 3){
                        int x;
                        cin >> x;

                        deque < int > q = {x};

                        int rear = r[x];
                        while(rear){
                                q.push_front(rear);
                                rear = r[rear];
                        }

                        int front = f[x];
                        while(front){
                                q.push_back(front);
                                front = f[front];
                        }

                        cout << q.size() << ' ';
                        while(!q.empty()){
                                cout << q.back() << ' ';
                                q.pop_back();
                        }
                        cout << '\n';
                }
        }

        return 0;
}
