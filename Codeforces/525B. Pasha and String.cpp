#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

int32_t main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    string s;
    cin >> s;
    int n = (int) s.size() , m;
    s = '?' + s;
    cin >> m;
    vector < int > par(n + 1 , 0) , sum(n + 1 , 0);
    while (m--){
        int x;
        cin >> x;
        par[x]++;
        if(n - x + 2 <= n) par[n - x + 2]--;
    }
    for (int i = 1; i <= n; ++i) {
        sum[i] += sum[i - 1] + par[i];
    }
    for (int i = 1; i * 2 <= n; ++i) {
        if(sum[i] % 2 == 0) continue;
        swap(s[i] , s[n - i + 1]);
    }
    for (int i = 1; i <= n; ++i) {
        cout << s[i];
    }
    return 0;
}
