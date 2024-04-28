class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        /*
            Using Prefix & Suffix sum arrays we can optimize the time complexity from O(n^2) to O(n).
            We also should use long long instead of int because the worst case the sum of the whole array
            will be 1e10 which can't be fit in int data type.
        */

        int n = (int) nums.size();

        // Build Prefix Sum array
        vector < long long > prefix_sum(n , 0LL);
        for (int i = 0 ; i < n ; ++i) {
            if (i == 0)
                prefix_sum[i] = nums[i];
            else
                prefix_sum[i] = prefix_sum[i - 1] + nums[i];
        }

        // Build Suffix Sum array
        vector < long long > suffix_sum(n + 1 , 0LL);
        for (int i = n - 1 ; i >= 0 ; --i) {
            if (i == n - 1)
                suffix_sum[i] = nums[i];
            else
                suffix_sum[i] = suffix_sum[i + 1] + nums[i];
        }

        // We need a variable to hold the minimum difference so far
        long long mn = INT64_MAX;

        // We also need a variable to hold the index of the minimum so far
        int idx;

        // Try each index i and try to minimize
        for (int i = 0 ; i < n ; ++i) {
            int n1 = i + 1; // number of prefix elements
            int n2 = ((n - i - 1) <= 0) ? 1 : n - i - 1; // number of suffix elements, watch out division by zero
            int diff = abs((prefix_sum[i] / n1) - (suffix_sum[i + 1] / n2));
            if (diff < mn) {
                mn = diff;
                idx = i;
            }
        }

        // return idx which holds the index of the minimum difference
        return idx;
    }
};
