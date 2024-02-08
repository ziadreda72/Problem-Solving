class Solution {
public:
    int numSquares(int n) {
        vector < int > dp(n + 1 , (int) 1e8);

        dp[0] = 0;
        for (int i = 0 ; i <= n ; ++i)
            for (int x = 1 ; x * x <= n ; ++x)
                if (i + (x * x) <= n)
                    dp[i + (x * x)] = min(dp[i + (x * x)] , dp[i] + 1);

        return dp.back();

    }
};
