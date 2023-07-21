class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = (int) nums.size();
        vector < int > dp(n , 1) , dp2(n , 1);
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < i ; ++j){
                if(nums[i] > nums[j]){
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        dp2[i] = 0;
                    }
                    if(dp[j] + 1 == dp[i]){
                        dp2[i] += dp2[j];
                    }
                }
            }
        }
        int mx = *max_element(dp.begin() , dp.end());
        int ret = 0;
        for(int i = 0 ; i < n ; ++i){
            if(dp[i] == mx){
                ret += dp2[i];
            }
        }
        return ret;
    }
};
