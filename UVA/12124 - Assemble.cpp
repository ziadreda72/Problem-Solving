#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solveTC() {
        int n , b;
        cin >> n >> b;
        map < string , vector < pair < int , int > > > mp;
        set < int > st;
        for (int i = 0; i < n; ++i) {
                string type , name;
                int p , q;
                cin >> type >> name >> p >> q;
                mp[type].emplace_back(p , q);
                st.insert(q);
        }
        for(auto& [_ , v] : mp)
                sort(v.begin(), v.end());
        int ans;
        for(auto x : st){
                int b2 = 0;
                bool ok = 1;
                for(auto [_ , v] : mp){
                        int mn = INT32_MAX;
                        bool found = 0;
                        for(auto [p , q] : v){
                                if(q >= x)
                                        mn = min(mn , p) , found = 1;
                        }
                        if(found)
                                b2 += mn;
                        else{
                                ok = 0;
                                break;
                        }
                }
                if(ok && b2 <= b)
                        ans = x;
        }
        cout << ans;
}

int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
	int tc = 1;
	cin >> tc;
	while(tc--){
		solveTC();
		cout << '\n';
	}
	return 0;
}
