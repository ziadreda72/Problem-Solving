class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = (int) prices.size();
        
        int ret = 0 , mx = 0;
        for (int i = n - 1 ; i >= 0 ; --i) {
            ret = max(ret , mx - prices[i]);
            mx = max(mx , prices[i]);
        }

        return ret;
    }
};
