        #include <bits/stdc++.h>

        using namespace std;
        using i64 = long long;

        int32_t main(){
                ios::sync_with_stdio(false);
                cin.tie(nullptr);

                int N;
                cin >> N;
                
                string S;
                cin >> S;

                int ans = 0;

                for(int i = 0 ; i < N ; ++i){
                        int A = 0 , T = 0 , C = 0 , G = 0;
                        for(int j = i ; j < N ; ++j){
                                if(S[j] == 'A') A++;
                                if(S[j] == 'T') T++;
                                if(S[j] == 'C') C++;
                                if(S[j] == 'G') G++;

                                ans += A == T && C == G;
                        }
                }

                cout << ans;

                return 0;
        }
