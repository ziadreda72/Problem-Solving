class Solution {
public:
    int characterReplacement(string s, int k) {
        /*
            Assume we have a substring "AAABBBAAA" and we want to make all letters the same, it's easy to
            see that changing B's to A will allow us to solve the task with minimum cost.
            Conclusion: if you have a string and you want to make all letters equal, change them to the letter
            with maximum number of appearances.
            Imagine you have a substring such that you need x changes to make it good(all the same)
            We will try to extend our string if x < k and we will shrink if x > k.
             This is an easy task, we will use sliding window method to solve it.
        */

        // We need frequency array to count the frequency of each letter in a substring
        vector < int > cnt(26, 0);

        // Try to maximize the answer among all good substrings, choose string with maximum size 
        int ans = 0;

        // We need a left pointer to indicate the starting position
        int l = 0;

        // The right pointer will be increased automatically in the for loop
        for (int r = 0; r < (int) s.size(); ++r) {
            cnt[s[r] - 'A']++;

            // while we can't achieve our goal, shrink the current substring
            while (!good(cnt, k)) {
                cnt[s[l] - 'A']--;
                l++;
            }

            // after we break the while loop, the current string is good, try to maximize the answer
            ans = max(ans, r - l + 1);
        } 

        return ans;
    }

    bool good(vector < int > &cnt, int k) {
        // find the maximum frequency
        int mx = 0;
        for (auto x : cnt)
            mx = max(mx, x);

        // changes will be the number of changes needed to make all the string of the same letter
        int changes = 0;
        for (auto x : cnt)
            changes += x;

        // subtract the value mx, because we will changes all characters to the character with frequency value mx
        changes -= mx;
        
        // return true if changes <= k, it means the string can be turned into string with equal letters
        return changes <= k;
    }
};
