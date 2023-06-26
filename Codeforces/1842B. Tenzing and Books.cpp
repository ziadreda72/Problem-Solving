#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solveTC() {
          int n , x;
          cin >> n >> x;
          vector < int > a(n) , b(n) , c(n);
          for(auto &i : a)
                    cin >> i;
          for(auto &i : b)
                    cin >> i;
          for(auto &i : c)
                    cin >> i;
          for (int i = 1; i < n; ++i) {
                    a[i] |= a[i - 1];
                    b[i] |= b[i - 1];
                    c[i] |= c[i - 1];
          }
          auto good = [&](int y){
                    bitset < 40 > X(x) , Y(y);
                    for (int i = 0; i < 35; ++i) {
                              if(X[i] == 0 && Y[i] == 1)
                                        return false;
                    }
                    return true;
          };
          vector < int > ans;
          for (int i = 0; i < n; ++i) {
                    if(good(a[i]))
                              ans.push_back(a[i]);
                    if(good(b[i]))
                              ans.push_back(b[i]);
                    if(good(c[i]))
                              ans.push_back(c[i]);
          }
          int x2 = 0;
          for(auto i : ans)
                    x2 |= i;
          cout << (x2 == x ? "Yes" : "No");
}

int32_t main() {
          ios::sync_with_stdio(false);cin.tie(nullptr);
          cout.tie(nullptr);cout.precision(20);
          int tc = 1;
          cin >> tc;
          while(tc--){
                    solveTC();
                    cout << '\n';
          }
          return 0;
}
