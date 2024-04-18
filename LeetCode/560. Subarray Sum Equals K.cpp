class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // We can optimize our brute force solution that works in O(n^2)
        // using prefix sums.
        // The key idea is that we are starting out sub-array at index "i"
        // we can translate our problem to "how many nums[i...j] such that sums[j] - sums[i - 1] == k"
        // where sums is the prefix sum array.
        // It's clear that "sums[j] = sums[i - 1] + k", the new problem is how to count all j's optimally.
        // Using the fact j >= i, we can store the indices of each element in sums in a hash-map then
        // binary search to get the lower bound(the first valid index).
        // So it's clear now that we can solve the problem in average time nlog(n)

        int n = (int) nums.size();

        // This hash-map will hold all indices for each element in our prefix array
        unordered_map < int , vector < int > > idx;

        // A nice trick to save memory is to use a variable instead of array and iterate twice
        int sum = 0;
        for (int i = 0 ; i < n ; ++i) {
            sum += nums[i];
            idx[sum].push_back(i);
        }

        // This variable holds our answer that we will return
        int ret = 0;

        // Now reset sum and iterate over each element
        sum = 0;
        for (int i = 0 ; i < n ; ++i) {
            // We need to check if "k + sums[i - 1]" exists
            int sumj = k + sum;
            if (idx.count(sumj)) {
                // we need to get the lower bound then consider each
                // index till the end of idx[sumj]
                ret += (int) (idx[sumj].end() - lower_bound(idx[sumj].begin() ,idx[sumj].end() , i));
            }
            sum += nums[i];
        }

        return ret;
    }
};
