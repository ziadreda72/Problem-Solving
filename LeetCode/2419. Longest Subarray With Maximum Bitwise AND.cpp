class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        /*
            There are three important observations:
            1. in binary representation, 2^i > sum(2^j from j = 0 to i - 1).
            2. to maximize the value of AND we should choose the maximum number of the array
            3. to maximize the size of the subarray that has the maximum AND value, search for a subarray
               consist of only maximum number.
        */

        // First, we find the maximum number in the array
        int mx = 0;
        for (auto &x : nums)
            mx = max(mx, x);


        // Last, using two pointers we search for maximum subarray size where each number in it equals mx
        int ret = 1;
        for (int l = 0; l < (int) nums.size(); ) {
            // We want nums[l] meet our condition
            if (nums[l] != mx) {
                ++l;
                continue;
            }

            // go right as much as you can till we find a number break our condition
            int r = l;
            while (r < (int) nums.size() && nums[r] == mx) ++r;
            ret = max(ret, r - l);
            l = r;
        }

        return ret;
    }
};
