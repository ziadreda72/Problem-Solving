class Solution {
public:
    int rob(vector<int>& nums) {
        int n = (int) nums.size();
        if (n == 1)
            return nums[0];
        vector < int > dp(n) , dp2(n);
        dp[0] = nums[0] , dp[1] = nums[1];
        dp2[0] = dp[0] , dp2[1] = max(dp[0] , dp[1]);
        for (int i = 2 ; i < n ; ++i) {
            dp[i] = max(dp[i] , dp2[i - 2] + nums[i]);
            dp2[i] = max(dp[i] , dp2[i - 1]);
        }
        return max(dp[n - 1] , dp[n - 2]);
    }
};
