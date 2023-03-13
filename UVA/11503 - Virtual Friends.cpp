#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

map < string , string > par;
map < string , int > sz;

void make_set(string s){
    par[s] = s;
    sz[s] = 1;
}

string find_set(string s){
    return par[s] = (par[s] == s ? s : find_set(par[s]));
}

void union_sets(string a , string b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        if(sz[a] < sz[b]) swap(a , b);
        par[b] = a;
        sz[a] += sz[b];
    }
}

void solve()
{
    int n;
    cin >> n;
    vector < pair < string , string  > > a;
    for (int i = 0; i < n; ++i) {
        string s , t;
        cin >> s >> t;
        a.emplace_back(s , t);
        make_set(s);
        make_set(t);
    }
    for (int i = 0; i < n; ++i) {
        string root = find_set(a[i].F);
        string root2 = find_set(a[i].S);
        if(root == root2){
            cout << sz[root] << '\n';
        }else{
            union_sets(a[i].F , a[i].S);
            root = find_set(a[i].F);
            cout << sz[root] << '\n';
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    int tc = 1;
    cin >> tc;
    while(tc--){
        solve();
//        cout << '\n';
    }
    return 0;
}
