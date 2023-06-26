#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

string s;
vector < int > need(3 , 0) , h(3 , 0) , p(3 , 0);
i64 r;

bool good(i64 x){
          vector < i64 > tot(3);
          for (int i = 0; i < 3; ++i) {
                    tot[i] = 1LL * need[i] * x;
          }
          i64 ret = 0;
          for (int i = 0; i < 3; ++i) {
                    ret += 1LL * max(0LL , tot[i] - h[i]) * p[i];
          }
          return ret <= r;
}

int32_t main() {
          ios::sync_with_stdio(false);cin.tie(nullptr);
          cout.tie(nullptr);cout.precision(20);
          cin >> s;
          need[0] = count(s.begin(), s.end() , 'B');
          need[1] = count(s.begin(), s.end() , 'S');
          need[2] = count(s.begin(), s.end() , 'C');
          for (int i = 0; i < 3; ++i) {
                    cin >> h[i];
          }
          for (int i = 0; i < 3; ++i) {
                    cin >> p[i];
          }
          cin >> r;
          i64 lo = 0 , hi = (i64) 1e13;
          while (hi - lo > 1){
                    i64 mid = lo + (hi - lo) / 2;
                    if(good(mid))
                              lo = mid;
                    else
                              hi = mid;
          }
          cout << lo;
          return 0;
}
