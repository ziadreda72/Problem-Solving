class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        // One property of powers of two is if we "and" this number "n" with "n - 1"
        // the result of this operation should be one
        // example:
        // n = 8 (1000 in binary)
        // n - 1 = 7 (0111 in binary)
        // 1000 & 0111 = 0
        return ((n & (n - 1)) == 0);
    }
};
