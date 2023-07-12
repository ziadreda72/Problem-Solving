#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const int di[] = {0 , 0 , -1 , -1 , -1 , 1 , 1 , 1};
const int dj[] = {1 , -1 , -1 , 0 , 1 , -1 , 0 , 1};

char g[8][8];
bool win;

void kill(bool x){
        cout << (x ? "WIN" : "LOSE");
        exit(0);
}

bool check(int i , int j){
        return (0 <= i && i < 8 && 0 <= j && j < 8);
}

void dfs(int t , int i , int j){
        if(win)
                kill(win);
        if(i - t >= 0 && g[i - t][j] == 'S')
                return;
        if(i - t + 1 >= 0 && i - t + 1 < 8 && g[i - t + 1][j] == 'S')
                return;
        if(t >= 8){
                win = 1;
                return;
        }
        dfs(t + 1 , i , j);
        for (int k = 0; k < 8; ++k) {
                int ni = i + di[k];
                int nj = j + dj[k];
                if(check(ni , nj))
                        dfs(t + 1 , ni , nj);
        }
}

int32_t main() {
        ios::sync_with_stdio(false);cin.tie(nullptr);
        cout.tie(nullptr);cout.precision(20);
        for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 8; ++j) {
                        cin >> g[i][j];
                }
        }
        dfs(0 , 7 , 0);
        kill(win);
        return 0;
}
