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
    vector < int > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector < int > a2 = a;
    sort(a2.begin(), a2.end());
    vector < int > v;
    for (int i = 0; i < n; ++i) {
        if(a[i] != a2[i]){
            v.push_back(i);
        }
    }
    if(v.size() > 2){
        cout << "NO";
        return 0;
    }
    if(v.empty()){
        cout << "YES";
        return 0;
    }
    swap(a[v[0]] , a[v.back()]);
    cout << (is_sorted(a.begin(), a.end()) ? "YES" : "NO");
    return 0;
}
