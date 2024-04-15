class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        // considering a candidate number it's first digit is x
        // the next digit should be x + 1
        // with the same logic if this number ending with y
        // with previous digit should be y - 1
        // so we can brute force over starting and ending digits
        // lets call them i & j
        // so the digits of a number should be like: i, i + 1, i + 2,...., j - 2, j - 1, j

        // we need some vector that stores our result
        // we need to sort it before we return because brute force
        // doesn't guarantee to find the answer in a sorted order
        vector < int > ret;

        // start brute forcing over the first digit from 1 to 9
        for (int i = 1 ; i <= 9 ; ++i) {
            // the ending digit will never be less than or equal to i
            for (int j = i + 1 ; j <= 9 ; ++j) {
                // now we generate a number containing all the digits
                // between i and j in order
                int num = 0;
                for (int k = i ; k <= j ; ++k)
                    num = num * 10 + k;
                
                // last thing we should do is to check if the generated
                // number lies in the input interval
                if (low <= num && num <= high)
                    ret.push_back(num);
            }
        }

        // don't forget to sort :"D
        sort(ret.begin() , ret.end());

        return ret;
    }
};
