#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

#define F first
#define S second

const int N = (int) 1e5 + 10;

int n;
string s;
int dp[N][3][2];

int solve(int i , int mod , bool emp){
    if(i >= n){
        if(emp || mod) return -1e8;
        return 0;
    }
    auto &ret = dp[i][mod][emp];
    if(~ret) return ret;
    int op = solve(i + 1 , mod , emp);
    int op2 = -1;
    if(s[i] == '0'){
        if (!emp){
            op2 = solve(i + 1 , mod , 0) + 1;
        }
    }else{
        op2 = solve(i + 1 , (mod + (s[i] - '0')) % 3 , 0) + 1;
    }
    return ret = max(op , op2);
}

void build(int i , int mod , bool emp){
    if(i >= n){
        return;
    }
    int op = solve(i + 1 , mod , emp);
    int op2 = -1;
    if(s[i] == '0'){
        if (!emp){
            op2 = solve(i + 1 , mod , 0) + 1;
        }
    }else{
        op2 = solve(i + 1 , (mod + (s[i] - '0')) % 3 , 0) + 1;
    }
    int optimal = solve(i , mod , emp);
    if(optimal == op){
        build(i + 1 , mod , emp);
    }else if(optimal == op2){
        cout << s[i];
        build(i + 1 , (mod + (s[i] - '0')) % 3 , 0);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cout.tie(nullptr);cout.precision(20);
    memset(dp , -1 , sizeof dp);
    cin >> s;
    n = (int) s.size();
    int sol = solve(0 , 0 , 1);
    if(sol < 0){
        if(s.find('0') == -1){
            cout << -1;
            return 0;
        }
        cout << 0;
        return 0;
    }
    build(0 , 0 , 1);
    return 0;
}
