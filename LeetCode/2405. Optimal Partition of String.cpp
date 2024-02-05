class Solution {
public:
    int partitionString(string s) {
        int ret = 0 , msk = 0;
        for (auto &c : s) {
            int cur_bit = c - 'a'; // [0 , 25]
            if ((msk >> cur_bit) & 1) {
                ++ret;
                msk = 0;
            }
            msk |= 1 << cur_bit;
        }
        ret += msk > 0;
        return ret;
    }
};
