class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        /*
            We can at least have a non-efficient working solution that runs in O(n^3).
            Simply we can try all possible sub-strings in O(n^2) and try to minimize the answer in O(n)
            if the sub-string meets the condition.
        */

        // we will return an empty string if there's no sub-string meets our condition
        string ret = "";

        // This indicates the length of the answer and we should minimize it as much as we can
        int len = INT32_MAX;

        for (int l = 0 ; l < (int) s.size() ; ++l) {
            string sub = "";
            for (int r = l ; r < (int) s.size() ; ++r) {
                sub += s[r];
                bool ok = count(sub.begin() , sub.end() , '1') == k;
                if (ok && len > (r - l + 1)) {
                    // If we find any shorter sub-string this is our first priority
                    ret = sub;
                    len = r - l + 1;
                } else if (ok && len == (r - l + 1)) {
                    // If it's already equal to the minimum so far, try to find lex samllest
                    ret = min(ret , sub);
                }
            }
        }

        return ret;
    }
};

/*
    Time: O(n^3)
    Space: O(n)
*/
