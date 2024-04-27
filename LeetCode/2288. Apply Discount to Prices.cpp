class Solution {
public:
    string discountPrices(string sentence, int discount) {
        cout.precision(2);
        /*
            We can find the answer with a single pass.
            We will modify only strings that start with "$" iff:
            1. There are characters after "$".
            2. All characters after "$" are digits.
            The new price can be calculated like: new_price = old_price * (1 - (discount / 100))
        */

        int n = (int) sentence.size();

        // This string will hold our answer  
        string ret;

        // Try to modify the sentence
        for (int i = 0 ; i < n ; ++i) {
            // Extract each word from the sentence and modify it if needed.
            int j;
            // We need a boolean variable to indicate if the word is price
            bool is_price = false;
            // We need another boolean to indicate if the sub-string after '$' is number
            bool all_digits = true;
            // We also need to save the word
            string word;
            for (j = i ; j < n && sentence[j] != ' ' ; ++j) {
                // If this is the first character, check if it's dollar sign.
                if (i == j && sentence[j] == '$') is_price = true;
                // Else, update all_digits value
                if (j > i) all_digits &= isdigit(sentence[j]);
                word += sentence[j];
            }

            // with these conditions, there's no need for modification
            if (!is_price || word.size() == 1 || !all_digits)
                ret += word + ' ';
            else {
                // This word is surely a price, need to apply the discout, but first convert from string to long long
                long long old_price = stoll(word.substr(1 , (int) word.size() - 1));
                long double discount_amount = (long double) (old_price * discount) / (long double) 100.00;
                long double new_price = old_price - discount_amount;

                // Convert the new price into string to add it to the answer
                string new_word = to_string(new_price);
                new_word = new_word.substr(0 , new_word.find('.') + 3);
                ret += '$' + new_word + ' ';
            }

            // jump to the next word
            i = j;
        }

        // There's additional space at the end of the string
        ret.pop_back();

        return ret;
    }
};
