class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int n = (int) nums.size();

        sort(nums.begin() , nums.end()); // O(nlog(n))

        int ret = -1 , l = 0 , r = n - 1;
        while (l < r) { // O(n)
            int sum = nums[l] + nums[r];
            if (sum >= k)
                --r;
            else {
                ret = max(ret , sum);
                ++l;
            }
        }
        
        return ret;
    }
};
