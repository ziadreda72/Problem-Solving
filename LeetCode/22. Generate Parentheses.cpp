class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Recall that the catalan numbers and valid parenthesis
        // have a relationship which lead us to O(n!) (factorial) time complexity
        // One way to optimize it a little is to get benefit from the fact
        // we only use "(" and ")" brackets.
        // Say we have a binary string of even length, 0101 for example
        // this string can be transformed into parenthesis string if we map
        // 0 ---> ( and 1 ---> )
        // 0101 becomes ()().
        // This allows us to write a complete search solution and extract only valid ones.
        // We can use stack data structure to check validity.

        // The input is n but the resulting parenthesis string has a size of 2n
        n += n;

        // We need a vector of string to store valid strings
        vector < string > ret;

        // Do the complete search using bitmasking, try every binary string of size 2n
        // from 0 to 2^(2n) - 1
        for (int msk = 0 ; msk < (1 << n) ; ++msk) {
            // We need a stack to check validity, this is a classical stack problem.
            // Recall we are mapping 000111 to ((())), so we need to check each bit from left
            // to right in the current bitmask.
            stack < int > s;

            // The current bitmask is valid if each opened bracket has its closed one
            // this can be translated into: 
            // "number of zeros equals number of ones and one will never become before zero"
            bool isValid = true;

            for (int i = n - 1 ; i >= 0 ; --i) {
                if (((1 << i) & msk) == 0) { 
                    // it's a zero (opened bracket), push it into the stack
                    s.push(0);
                } else {
                    // it's a one (closed bracket), check the stack is not empty
                    // then pop once
                    if (s.empty()) {
                        // The stack is empty means one has come before zero
                        // the string isn't valid
                        isValid = false;
                        break;
                    }
                    s.pop();
                }
            }

            // if we finish and the stack is not empty, zeros are more than ones
            if (s.size()) isValid = false;

            // if the string is valid, just replace each zero with opened and one with closed
            // then push it into the ret vector
            if (isValid) {
                string par;
                for (int i = n - 1 ; i >= 0 ; --i) {
                    if ((1 << i) & msk) par.push_back(')');
                    else par.push_back('(');
                }
                ret.push_back(par);
            }
        }

        return ret;
    }
};

/*
Time: O(2^n)
Space: O(n)
*/
