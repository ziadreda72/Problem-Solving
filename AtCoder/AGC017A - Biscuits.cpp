#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

const int N = 55;

int n , p;
i64 a[N] , dp[N][2];

i64 solve(int i , int j){
  if(i >= n){
    return j == p;
  }
  auto &ret = dp[i][j];
  if(~ret){
    return ret;
  }
  ret = 0;
  return ret = solve(i + 1 , j) + solve(i + 1 , (j + a[i]) % 2);
}

int32_t main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> p;
  for(int i = 0 ; i < n ; ++i) cin >> a[i];
  memset(dp , -1 , sizeof dp);
  cout << solve(0 , 0);
  return 0;
}
