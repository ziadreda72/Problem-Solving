#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        string s;
        cin >> s;
        sort(s.begin() , s.end());
        string s2 = "abc";
        do{
                int i = 0;
                string s3;
                while(s3.size() < s.size()){
                        s3.push_back(s2[i]);
                        i = (i + 1) % 3;
                }
                sort(s3.begin() , s3.end());
                if(s == s3){
                        cout << "YES";
                        return 0;
                }
        }while(next_permutation(s2.begin() , s2.end()));
        cout << "NO";
        return 0;
}
