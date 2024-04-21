class Solution {
public:
    string minRemoveToMakeValid(string s) {
        /*
            This problem is a classical valid parenthsis with a stack with a little modification.
            Characters to be removed can be:
            1. a closed bracket with no opened
            2. an opened bracket with no closed after we finished iterating the string
            so we can hold a hash set of integers that holds the indices of the characters to be removed.
            To know which opened brackets to be removed we can use a stack of integers which holds the
            indices of the opened brackets to be removed.
        */

        // stack to hold indices of opened
        stack < int > opIdx;

        // hash set to hold indices to be removed
        unordered_set < int > removed;

        for (int i = 0 ; i < (int) s.size() ; ++i) {
            if (s[i] == '(') // save the index of opened bracket
                opIdx.push(i);
            else if (s[i] == ')') {
                // There are two case, if stack is empty we will remove that character
                // else this is a valid parenthsis
                if (opIdx.empty()) removed.insert(i);
                else opIdx.pop();
            }
        }

        // After we finish iterating, all indices in the stack (if exist) should be removed
        while (!opIdx.empty()) {
            removed.insert(opIdx.top());
            opIdx.pop();
        }

        // now we will build the resulting string after ignoring the indices to be removed
        string ret;
        for (int i = 0 ; i < (int) s.size() ; ++i) {
            if (removed.count(i)) continue;
            ret.push_back(s[i]);
        }

        return ret;
    }
};

/*
    Time: O(n)
    Space: O(n)
*/
