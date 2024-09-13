class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        /*
            An O(n^2) solution can be easily optimized to O(n) using prefix XOR array.
            The idea is that if we want the result of XOR of the subarray [l, r] we can easily
            compute the answer using this formula: answer = prefix_xor[r] XOR prefix_xor[l - 1]
            because prefix_xor[r] also have prefix_xor[l - 1] implicitly, and XORing a subarray twice will cancle it
        */

        int n = (int) arr.size();

        // we need to precalculate the prefix xor array
        vector < int > prefix_xor(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            prefix_xor[i] = prefix_xor[i - 1] ^ arr[i - 1];

        // we will push to the answer array the value prefix_xor[r + 1] - prefix_xor[l]
        // because l, r in the input are 0-based indices
        vector < int > ret;
        for (int i = 0; i < (int) queries.size(); ++i) {
            int l = queries[i][0], r = queries[i][1];
            ret.push_back(prefix_xor[r + 1] ^ prefix_xor[l]);
        }

        return ret;
    }
};
