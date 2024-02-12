class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ret = 0 , maj = (int) nums.size() / 2;
        for (int bit = 0 ; bit < 32 ; ++bit) {
            int cnt = 0;
            for (auto &x : nums)
                if ((x >> bit) & 1)
                    ++cnt;
            if (cnt > maj)
                ret |= 1 << bit;    
        }
        return ret;
    }
};
/*
Time: O(cn) where c ~= 30
Space: O(1)
*/
