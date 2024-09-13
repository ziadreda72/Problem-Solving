class Solution {
public:
    int numDifferentIntegers(string word) {
        /*
            This is a simulation problem, we just need to take care of leading zeros
            and integer overflow, so we can save integers in a string instead
        */

        // We need a hash map to save unique integers
        unordered_set < string > uni_int;

        // Now we iterate over the string backward to easily get rid of leading zeros
        while (!word.empty()) {
            // if the current character isn't a digit we continue
            if (!isdigit(word.back())) {
                word.pop_back();
                continue;
            }
            
            // if it's a digit we should group all digits together to form a number
            // We will save the digits in a string to avoid overflow
            string num;

            // we will loop until we find a character or we reach the front of the input
            while (!word.empty() && isdigit(word.back())) {
                num.push_back(word.back());
                word.pop_back();
            }

            // Now we get rid of leading zeros then save it in the hashmap
            while (!num.empty() && num.back() == '0') num.pop_back();
            uni_int.insert(num);
        }

        return (int) uni_int.size();
    }
};
