#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        i64 X , A , D , N;
        cin >> X >> A >> D >> N;

        if(D < 0){
                A = A + (N - 1) * D;
                D *= -1;
        }

        if(X <= A){
                cout << A - X;
                return 0;
        }

        if(X >= (A + (N - 1) * D)){
                cout << X - (A + (N - 1) * D);
                return 0;
        }

        i64 lo = 0 , hi = N - 1;
        while(hi - lo > 1){
                i64 mid = (lo + hi) / 2;
                if(A + mid * D <= X){
                        lo = mid;
                }else{
                        hi = mid;
                }
        }

        i64 L = A + lo * D , R = A + (lo + 1) * D;

        cout << min(X - L , R - X);

        return 0;
}
