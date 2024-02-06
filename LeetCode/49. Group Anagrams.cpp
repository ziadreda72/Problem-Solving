class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map < vector < short > , vector < string > > mp;
      
        for (auto &s : strs) {
            vector < short > freq(26 , 0);
            for (auto &c : s)
                ++freq[c - 'a'];
            mp[freq].push_back(s);
        }

        vector < vector < string > > ret;
        for (auto &[freq , v] : mp) 
            ret.push_back(v);
      
        return ret;
    }
};
