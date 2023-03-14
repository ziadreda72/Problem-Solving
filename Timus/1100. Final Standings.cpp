#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

struct team{
    int id , m , i;

    team(){}
};

int32_t main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    int n;
    cin >> n;
    vector < team > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].id >> a[i].m;
        a[i].i = i;
    }
    sort(a.begin(), a.end() , [](team a , team b){
       if(a.m == b.m){
           return a.i < b.i;
       }
        return a.m > b.m;
    });
    for(auto x : a){
        cout << x.id << ' ' << x.m << '\n';
    }
    return 0;
}
