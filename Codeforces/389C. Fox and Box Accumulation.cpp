#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    int n;
    cin >> n;
    multiset < int > mst;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        mst.insert(x);
    }
    vector < int > a(mst.begin(), mst.end());
    int ans = 0;
    while (!a.empty()){
        vector < int > v;
        int x = a[0];
        mst.erase(mst.find(x));
        v.push_back(x);
        while (true){
            auto it = mst.lower_bound(v.size());
            if(it == mst.end())
                break;
            v.push_back(*it);
            mst.erase(it);
        }
        a = vector < int > (mst.begin(), mst.end());
        ans++;
    }
    cout << ans;
    return 0;
}
