#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        const int MAX = (int) 2e5 + 5;

        vector < multiset < int > > box(MAX);
        vector < set < int > > card(MAX);

        int N , Q;
        cin >> N >> Q;

        while(Q--){
                int t;
                cin >> t;

                if(t == 1){
                        int i , j;
                        cin >> i >> j;
                        box[j].insert(i);
                        card[i].insert(j);
                }else{
                        int i;
                        cin >> i;
                        if(t == 2){
                                for(auto x : box[i]) cout << x << ' ';
                        }else{
                                for(auto x : card[i]) cout << x << ' ';
                        }
                        cout << '\n';
                }
        }

        return 0;
}
