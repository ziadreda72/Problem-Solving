class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int mnSz = 1000;
        for (auto &s : strs)
            mnSz = min(mnSz , (int) s.size());

        string ret;
        for (int i = 0 ; i < mnSz ; ++i) {
            int msk = 0;
            for (auto &s : strs)
                msk |= 1 << (s[i] - 'a');
            if (__builtin_popcount(msk) == 1)
                ret += char ('a' + __builtin_ctz(msk));
            else
                break;    
        } 

        return ret;
    }
};
