class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector < vector < int > > dp(numRows);
        for (int i = 0 ; i < numRows ; ++i)
            dp[i].assign(i + 1 , 0);
      
        dp[0][0] = 1;
        for (int i = 1 ; i < numRows ; ++i) {
            for (int j = 0 ; j < (int) dp[i].size() ; ++j) {
                int x = j - 1 >= 0 ? dp[i - 1][j -1] : 0;
                int y = j < (int) dp[i - 1].size() ? dp[i - 1][j] : 0;
                dp[i][j] = x + y;
            }
        }
      
        return dp;
    }
};
