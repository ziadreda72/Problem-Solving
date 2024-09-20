class Solution {
public:
    bool isPalindrome(string s) {
        // Using two pointers l, r:
        // l: current alphanumeric character from the left
        // r: current alphanumeric character from the right
        // check the false condition to return false, or return true at the ned

        int l = 0, r = (int) s.size() - 1;
        while (l < r) {
            // skip all non-alphanumeric
            while (l < (int) s.size() && !(isalpha(s[l]) || isdigit(s[l]))) ++l;
            while (r >= 0 && !(isalpha(s[r]) || isdigit(s[r]))) --r;

            // if r < l, we already checked all characters, we are done here
            if (r <= l)
                break;

            // check if they're both digits or characters and are the same, if not return false
            if (
                isdigit(s[l]) && isdigit(s[r]) && s[l] == s[r] ||
                isalpha(s[l]) && isalpha(s[r]) && tolower(s[l]) == tolower(s[r])) {
                ++l, --r;
                continue;               
            }
            
            return false;
        }

        // string is a palindrome, return true
        return true;
    }
};
