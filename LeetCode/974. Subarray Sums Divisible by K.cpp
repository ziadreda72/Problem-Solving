class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        /*
            When we say there is a subarray [l, r] with sum divisible by k,
            it means (prefix[r] - prefix[l - 1]) % k == 0, where prefix[i] is the sum of prefix ending with index i.
            We can simplify the previous formula to  (prefix[r] % k - prefix[l - 1] % k) == 0
            which means we need two indices i and j where (prefix[i] % k) equals (prefix[j] % k).
            But how many subarrays are there if we have n prefixes % k are equal? nC2.
            So we can easily solve the problem with the help of hashmaps.
        */

        // Here we will save the frequency of the prefixes mod k
        unordered_map < int, int > mp;
        
        // This is important because we may have negative integers that may cause a subarray sum equals zero
        ++mp[0];

        // We don't need prefix sum array actually, just sum the input and save the result in the hashmap 
        int s = 0;
        for (int i = 0; i < (int) nums.size(); ++i) {
            s += nums[i];
            // "(s % k) + k) % k" just to avoid negative remainders
            mp[((s % k) + k) % k]++;
        }

        // Now we calcualate the result where nC2 = n * (n - 1) / 2 
        int ret = 0;
        for (auto [_, n] : mp)
            ret += n * (n - 1) / 2;

        return ret;
    }
};
