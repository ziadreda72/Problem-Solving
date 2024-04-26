class Solution {
public:
    vector<string> letterCombinations(string digits) {
        /*
            First we need to know how to map a digit to ll possible character.
            We can notice that all digits from 2 to 9 map to 3 different characters expect for 7 and 9 
            they map to 4 different characters.
            We can build an array called "howMany" where howMany[i] = how many characters digits i can map to,
            then we build a prefix sum array to know how many characters mapped to a certain digits, so we can say
            prefixSum[i] = how many characters they've been already mapped for all j < i, so if we face digit 3 for example
            we know "abc" they've been mapped to 2, we can map starting from "d" (which is "a" + 3 in ascii) to "f" ("a" + 5 in ascii).
            Then we can build all possible strings using backtracking and this is neccessary because digits.size is not fixed, means
            we can't build a dynamic iterative approach.
        */

        // If input is empty return an empty vector to avoid uneccessary overhead
        if (digits.empty()) 
            return {};

        // howMany will be an array of 3's expect for 7 and 9
        howMany.assign(10 , 3);
        howMany[7] = howMany[9] = 4;

        // Build the prefix sum array
        prefixSum.assign(10 , 0);
        for (int i = 2 ; i < 10 ; ++i)
            prefixSum[i] = prefixSum[i - 1] + howMany[i];

        // Start backtrack and get all possible combinations
        backTrack(0 , digits);

        return ret;
    }

private:
    vector < int > howMany , prefixSum;
    vector < string > ret; // The returning string we will push all possible strings during the backtracking
    string s; // This string will be used in backtracking to hold the current combination

    void backTrack(int i , string &digits) {
        if (i >= digits.size()) {
            ret.push_back(s);
            return;
        }

        int j = digits[i] - '0'; // this is the index of digits[i] in howMany and prefixSum

        // Get all characters digits[i] can map to then try all possible combinations
        for (char c = 'a' + prefixSum[j - 1] ; c < 'a' + prefixSum[j - 1] + howMany[j] ; ++c) {
            s.push_back(c);
            backTrack(i + 1 , digits);
            s.pop_back();
        }
    }
};

/*
    Time: O(4^n)
    Space: O(4^n)
*/
