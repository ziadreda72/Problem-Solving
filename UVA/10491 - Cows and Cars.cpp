#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        long double cow , car , show;
        while (cin >> cow >> car >> show){
                cout << fixed << setprecision(5);
                if(show == 0){
                        cout << (car / (car + cow)) << '\n';
                }else{
                        long double tot = cow + car;
                        long double res = ((cow / tot) * (car / (tot - show - 1))) + ((car / tot) * ((car - 1) / (tot - show - 1)));
                        cout << res << '\n';
                }
        }
        return 0;
}
