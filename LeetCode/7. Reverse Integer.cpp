class Solution {
public:
    int reverse(int x) {
        // For simplicity, we can work on the absolute value
        // with keeping an indicator if the number is negative.
        bool isNegative = x < 0;
        x = abs(x);

        // There are two cases in this problem, considring the number of digits
        // of the number compare to the number of digits of INT_MAX.

        // If less, we can always reverse 
        if (getNumSize(x) < getNumSize(INT_MAX)) {
            int ret = 0;
            while (x) {
                ret = ret * 10 + (x % 10);
                x /= 10;
            }
            return (isNegative ? -ret : ret);
        }

        // If equal, we need to keep track the last digit of x will never exceed
        // the first digit of INT_MAX and so on
        
        // We will store INT_MAX as a string to easily iterate from left to right
        string mx = to_string(INT_MAX);

        // We need a boolean to keep track if the reversed number becomes less
        // if so, we can keep reversing without comparing
        bool isLess = false;

        int ret = 0 , i = 0;
        while (x) {
            if (!isLess && ((x % 10) > (mx[i] - '0'))) {
                // The reversed number will exceed INT_MAX, we return 0
                ret = 0;
                break;
            } else if ((x % 10 < (mx[i] - '0'))) {
                isLess = true;
            }
            // Do the reversing operation
            ret = ret * 10 + (x % 10);
            x /= 10;
            ++i;
        }

        return (isNegative ? -ret : ret);
    }

    int getNumSize(int x) {
        // This function returns the size of a number(the number of digits)
        int ret = 0;
        while (x) {
            ++ret;
            x /= 10;
        }
        return ret;
    }
};
