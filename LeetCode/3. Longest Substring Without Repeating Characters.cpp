class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // One possible approach is to use sliding-window method
        // assume sub-string [l , r] is good, this means all sub-sub-string
        // are also good, this allows to try to extend our anwer buy moving r right
        // if sub-string are not good, move l right until becomes good
        
        // Now we need a hash-map to store the frequencies of each character
        // sub-string is called good if the frequency of each character is
        // no more than one
        unordered_map < char , int > freq;

        int n = (int) s.size() , l = 0 , ret = 0;
        for (int r = 0 ; r < n ; ++r) {
            ++freq[s[r]];
            while (!good(freq))
                --freq[s[l++]];
            if (good(freq))
                ret = max(ret , r - l + 1);
        }

        return ret;
    }

    bool good(unordered_map < char , int > &mp) {
        bool ret = 1;
        for (auto &[_ , val] : mp)
            ret &= val <= 1;
        return ret;
    }
};

/*
Time: O(n)
Space: O(min(n , m)) where m is the maximum number of unique characters
*/
