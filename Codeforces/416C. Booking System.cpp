#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

struct group{
    int c , p , i;

    group(){}

    bool operator < (const group& other) const{
        if(p == other.p){
            return c < other.c;
        }
        return p < other.p;
    }
};

int32_t main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    int n;
    cin >> n;
    vector < group > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].c >> a[i].p;
        a[i].i = i + 1;
    }
    sort(a.rbegin(), a.rend());
    int k;
    cin >> k;
    multiset < int > st;
    map < int , vector < int > > mp;
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        st.emplace(x);
        mp[x].push_back(i + 1);
    }
    i64 tot = 0;
    vector < pair < int , int > > ans;
    for (int i = 0; i < n && !st.empty(); ++i) {
        auto it = st.lower_bound(a[i].c);
        if(it == st.end()) continue;
        ans.emplace_back(a[i].i , *it);
        tot += a[i].p;
        st.erase(it);
    }
    cout << (int) ans.size() << ' ' << tot << '\n';
    for(auto [x , y] : ans){
        cout << x << ' ' << mp[y].back() << '\n';
        mp[y].pop_back();
    }
    return 0;
}
