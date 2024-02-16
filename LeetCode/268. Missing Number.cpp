class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = (int) nums.size();

        // Given that all numbers are unique and in the range of [0 , n]
        // so we can just say the answer will always be unique also
        // if we know the sum of all numbers in [0 , n] say it "S"
        // and we know the sum of the array say it "s"
        // the answer will be ans = S - s
        int S = (n * (n + 1)) >> 1, s = 0;
        for (auto &x : nums) s += x;

        return S - s;
    }
};
