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

----------------------------------------------------------------------------------------------------------------------------

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        /*
            Is O(n^3) necessary? Actually, no we can come up with O(n^2) solution.
            Notice that the string is binary and a good string is the string with number of ones equals "k"
            we can reform the problem to: 
            "find the shortest sub-string with sum equals k, and if there are many return the lexicographically smallest".
            Let's fix index "i", we can proof that there's at most one sub-string which its sum equals k and it's the shortest
            for all sub-string starting from i and meet the above condition, but why?
            Assume s = "110010000" , k = 3.
            If we are at index 0, how many sub-string you can find is such a way they meet the condition? 5.
            So there is important observation, just find the first index right after "i" that meets the condition.
            This is an easy task to solve using prefix sums and binary search.
            Another important observation that there is at most n sub-string we will search among them for the answer.
            Assume search for shortest and lexicographically smallest answer costs O(n) and we have O(n) sub-string,
            so the total time complexity will be O(n^2).
        */

        int n = (int) s.size();

        // Build a prefix sum array to easily find the sum of a sub-string
        vector < int > pref(n , 0);
        for (int i = 0 ; i < n ; ++i) {
            if (i == 0) {
                pref[i] = s[i] == '1';
            } else {
                pref[i] = pref[i - 1] + (s[i] == '1');
            }
        }

        // We need vector of pairs to hold the left and right bounds for good sub-strings we found
        vector < pair < int , int > > good;

        // Do binary search for each index "i" and if it meets the condition push it to "good"
        for (int l = 0 ; l < n ; ++l) {
            // we are searching for index "r" which is the closest index to "l" such that pref[r] - pref[l - 1] == k
            // it means we could binary search for "k" if l == 0 or "k + pref[l - 1]" if l > 0
            // lower bound function will return the first index such that greater than or equal to value we search for
            // so we need an additional check that pref[r] == value we search for, and if it is, we continue
            int need = l == 0 ? k : pref[l - 1] + k;
            int r = lower_bound(pref.begin() + l , pref.end() , need) - pref.begin();
            if (r < n && pref[r] == need)
                good.emplace_back(l , r);
        }

        // Now we search for the answer among all sub-strings we've found
        string ret = "";
        for (auto &[l , r] : good) {
            string sub = s.substr(l , r - l + 1);
            if (ret.empty()) 
                ret = sub;
            else if (sub.size() == ret.size()) {
                // lengths are equal search for the lexicographically smallest
                ret = min(ret , sub);
            } 
            else if (sub.size() < ret.size()) {
                // lengths are not equal but we've found a shorter answer
                ret = sub;
            }
        }

        return ret;
    }
};

/*
    Time: O(n^2 + nlog(n))
    Space: O(n)
*/
