#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int sx , sy , tx , ty;
        cin >> sx >> sy >> tx >> ty;

        int dx = tx - sx , dy = ty - sy;

        cout << string(dx , 'R') << string(dy , 'U');
        cout << string(dx , 'L') << string(dy + 1 , 'D');
        cout << string(dx + 1 , 'R') << string(dy + 1 , 'U') << 'L';
        cout << 'U' << string(dx + 1 , 'L') << string(dy + 1 , 'D') << 'R';
        

        return 0;
}
