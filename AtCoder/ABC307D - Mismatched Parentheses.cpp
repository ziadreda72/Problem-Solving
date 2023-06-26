#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int32_t main() {
          ios::sync_with_stdio(false);cin.tie(nullptr);
          cout.tie(nullptr);cout.precision(20);
          int n;
          string s;
          cin >> n >> s;
          vector < int > open;
          set < int > closed;
          for (int i = 0; i < n; ++i) {
                    if(s[i] == '(')
                              open.push_back(i);
                    else if(s[i] == ')')
                              closed.insert(i);
          }
          vector < int > part(n , 0);
          while (!open.empty()){
                    int i = open.back();
                    open.pop_back();
                    if(closed.lower_bound(i) == closed.end())
                              continue;
                    int j = *closed.lower_bound(i);
                    closed.erase(closed.lower_bound(i));
                    part[i]++;
                    if(j + 1 < n)
                              part[j + 1]--;
          }
          for (int i = 1; i < n; ++i) {
                    part[i] += part[i - 1];
          }
          for (int i = 0; i < n; ++i) {
                    if(part[i])
                              continue;
                    cout << s[i];
          }
          return 0;
}
