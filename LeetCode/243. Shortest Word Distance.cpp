class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int n = (int) wordsDict.size();
        int idx1 = -1; // to store the index of the last time we see word1
        int idx2 = -1; // same as idx1 but for word2
        int ret = (int) 1e9;

        for (int i = 0 ; i < n ; ++i) {
            if (wordsDict[i] == word1)
                idx1 = i;
            if (wordsDict[i] == word2)
                idx2 = i;
            if (idx1 > -1 && idx2 > -1)
                ret = min(ret , abs(idx1 - idx2));
            if (ret == 1)
                return ret;
        }

        return ret;
    }
};

/*
Time: O(n)
Space: O(1)
*/
