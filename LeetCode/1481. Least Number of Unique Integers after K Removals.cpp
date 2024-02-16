class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // We need to count frequencies of each number, we can use a hash-map
        // which calculate frequencies in O(n) time O(n) space
        unordered_map < int , int > mp;
        for (auto &x : arr)
            ++mp[x];

        // We know that the maximum value of frequency of a number never
        // exceeds the size of input array, so we can use counting array
        // to iterate from the least to the most value of frequency
        vector < int > cnt((int) arr.size() + 1 , 0);
        for (auto &[_ , val] : mp)
            ++cnt[val];

        // Simply, to minimize the number of unique elements just try to delete
        // the number with least frequency if k >= cnt[x]
        int ret = 0;
        for (int i = 1 ; i <= (int) arr.size() ; ++i) {
            if (!cnt[i]) continue;
            if (!k) {
                // this means we can't delete and add it to the answer
                ret += cnt[i];
                continue;
            }
            // if cnt[i] == 2, this means we have two unique numbers with frequency i
            // try to delete them all, because if we don't, we will never go for better answer
            int total = i * cnt[i]; // the total number of array elements we need to delete
            int mn = min(k , total); // the maximum number of array elements we can delete
            total -= mn;
            k -= mn;
            if (total) {
                // this means k is zero and we can't delete them all
                ret += total / i + (total % i > 0);
            }
        }

        return ret;
    }
};
