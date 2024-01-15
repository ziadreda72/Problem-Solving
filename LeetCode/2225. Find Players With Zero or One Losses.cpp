class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map < int , vector < int > > mp;
        for (auto v : matches) {
            auto w = v[0] , l = v[1];
            
            if (mp.find(w) != mp.end())
                ++mp[w][0] , ++mp[w][1];
            else
                mp[w] = {1 , 1};
            
            if (mp.find(l) != mp.end())
                ++mp[l][0];
            else
                mp[l] = {1 , 0};
            
        }
        
        vector ret(2 , vector < int >());
        for (auto &[key , val] : mp) {
            if (val[0] == val[1])
                ret[0].push_back(key);
            else if (val[1] + 1 == val[0])
                ret[1].push_back(key);
        }
        
        return ret;
    }
};
