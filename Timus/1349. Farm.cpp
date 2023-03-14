#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

int32_t main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    int n;
    cin >> n;
    cout << ((n == 1 || n == 2) ? (n == 1 ? "1 2 3" : "3 4 5") : "-1");
    return 0;
}
