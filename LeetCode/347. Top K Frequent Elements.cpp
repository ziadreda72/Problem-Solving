class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /*
            We shall write a O(nlog(n)) solution then we shall try to optimize it.
            Noticing that if we know the frequency of each element we have, we can
            sort them based on their frequencies in descending order.
            Now we can split the problem into two parts.
            First: count the frequency in hash-map in average time O(n)
            Second: we are going to use max-heap of pairs [first, second] and the max
            first comes first, we will take the top of the heap k times and this valid
            because the problem constraints tells us the number of uniqe elements more
            than or equal to k. 
        */

        // First count the frequency
        unordered_map < int , int > freq;
        for (auto &x : nums) ++freq[x];

        // Second store [key, value] pairs of the hash-map as [value, key] pair in the heap
        priority_queue < pair < int , int > > maxHeap;
        for (auto [key , val] : freq) maxHeap.push({val , key});

        // Last we iterate over the heap k times and store the second element of the pair
        // in some vector to be returned
        vector < int > ret;
        while (k-- && !maxHeap.empty()) {
            ret.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return ret;
    }
};

/*
    Time: O(nlog(n) + klog(n))
    Space: O(M) where M is the number of unique elements in "nums"
*/
