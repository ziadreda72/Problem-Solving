class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        /*
            Consider having two pointers l,r initially l points the first element and r points the last.
            There are three cases:
            1. numbers[l] + numbers[r] == target -> return l,r
            2. numbers[l] + numbers[r] > target -> we need to reduce the sum, so decrement r by 1
            3. numbers[l] + numbers[r] < target -> we need to increase the sum, so increment l by 1
        */

        int l = 0, r = (int) numbers.size() - 1;
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum == target)
                return {l + 1, r + 1};
            if (sum > target)
                --r;
            else
                ++l;
        }

        // dummy vector
        return {-1, -1};
    }
};
