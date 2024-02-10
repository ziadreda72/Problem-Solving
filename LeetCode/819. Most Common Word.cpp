class Solution {
public:

    const string symbol = "!?',;.";

    string mostCommonWord(string paragraph, vector<string>& banned) { // O(paragraph.size + banned.size)
        unordered_set < string > st(banned.begin() , banned.end()); // O(banned.size)
        unordered_map < string , int > mp = getFrequencyMap(paragraph); // O(paragraph.size())
        return getMostFrequent(mp , st); // O(mp.size)
    }

    unordered_map < string , int > getFrequencyMap(string &paragraph) {
        unordered_map < string , int > mp;

        string s;
        for (int i = 0 ; i < (int) paragraph.size() ;) {
            if (isalpha(paragraph[i])) {
                s += tolower(paragraph[i]);
                ++i;
            }else {
                ++mp[s];
                s.clear();
                while(i < (int) paragraph.size() && !isalpha(paragraph[i]))
                    ++i;
            }
        }

        if (s.size())
            ++mp[s];

        return mp;
    }

    string getMostFrequent(unordered_map < string , int > &mp , unordered_set < string > &banned) {
        string ret;
        int mx = 0;

        for (auto &[key , val] : mp) {
            if (!banned.count(key)) {
                if (val > mx) {
                    mx = val;
                    ret = key;
                }
            }
        }

        return ret;
    }
};
