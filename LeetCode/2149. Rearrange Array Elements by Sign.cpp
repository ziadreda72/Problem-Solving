class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = (int) nums.size();
        vector < int > ret(n);
        int pos = 0 , neg = 1;
        for (auto &x : nums) {
            if (x > 0) {
                ret[pos] = x;
                pos += 2;
            } else {
                ret[neg] = x;
                neg += 2;
            }
        }
        return ret;
    }
};

/*
Time: O(n)
Space: O(n)
*/
