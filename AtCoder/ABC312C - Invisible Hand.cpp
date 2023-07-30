#include <bits/stdc++.h>

using namespace std;

#define int long long

int n , m;
vector < int > a , b;

int L(int x){
        int lo = -1 , hi = n;
        while (hi - lo > 1){
                int mid = (lo + hi) / 2;
                if(a[mid] <= x)
                        lo = mid;
                else
                        hi = mid;
        }
        return lo + 1;
}

int R(int x){
        int lo = -1 , hi = m;
        while (hi - lo > 1){
                int mid = (lo + hi) / 2;
                if(b[mid] >= x)
                        hi = mid;
                else
                        lo = mid;
        }
        return m - hi;
}

int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
                int x;
                cin >> x;
                a.push_back(x);
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                b.push_back(x);
        }
        sort(b.begin(), b.end());
        int lo = -1 , hi = 1E10;
        while (hi - lo > 1){
                int mid = (lo + hi) / 2;
                int x = L(mid) , y = R(mid);
                if(x >= y)
                        hi = mid;
                else
                        lo = mid;
        }
        cout << hi;
        return 0;
}
