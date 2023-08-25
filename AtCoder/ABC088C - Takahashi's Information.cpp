#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
using ld = long double;

#define F first
#define S second

vector < int > get(vector < int > &v , int x){
        vector < int > ret;
        for(auto i : v)
                ret.push_back(i - x);
        return ret;
}

int32_t main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        vector < vector < int > > c(3 , vector < int > (3));
        for(int i = 0 ; i < 3 ; ++i)
                for(int j = 0 ; j < 3 ; ++j)
                        cin >> c[i][j];
        for(int i = 0 ; i <= 100 ; ++i){
                for(int j = 0 ; j <= 100 ; ++j){
                        for(int k = 0 ; k <= 100 ; ++k){
                                set < vector < int > > st;
                                st.insert(get(c[0] , i));
                                st.insert(get(c[1] , j));
                                st.insert(get(c[2] , k));
                                if(st.size() == 1){
                                        cout << "Yes";
                                        return 0;
                                }
                        }
                }
        }
        cout << "No";
        return 0;
}
