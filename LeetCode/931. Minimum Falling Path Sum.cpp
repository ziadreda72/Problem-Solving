class Solution {
public:
    
    const int INF = (int) 1e9;
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = (int) matrix.size();
        vector dp(n , vector < int > (n , INF));
        for (int i = 0 ; i < n ; ++i)
            dp[0][i] = matrix[0][i];
        for (int i = 1 ; i < n ; ++i) {
            for (int j = 0 ; j < n ; ++j) {
                dp[i][j] = min(dp[i][j] , dp[i - 1][j] + matrix[i][j]);
                if (j - 1 >= 0)
                    dp[i][j] = min(dp[i][j] , dp[i - 1][j - 1] + matrix[i][j]);
                if (j + 1 < n)
                    dp[i][j] = min(dp[i][j] , dp[i - 1][j + 1] + matrix[i][j]);
            }
        }
        return *min_element(dp.back().begin() , dp.back().end());
    }
};
