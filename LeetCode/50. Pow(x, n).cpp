class Solution {
public:
    double myPow(double x, int n) {
        bool is_negative = n < 0;
        n = abs(n);
        double ret = (double) 1.0;
        while (n) {
            if (n & 1) ret *= x;
            x *= x;
            n >>= 1;
        }
        if (is_negative)
            return 1.0 / ret;
        return ret;
    }
};
