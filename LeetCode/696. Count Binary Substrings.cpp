class Solution {
public:
    int countBinarySubstrings(string s) {
        int ret = 0 , n = (int) s.size();

        vector < pair < char , int > > v;
        for (int i = 0 ; i < n ; ++i) {
            if (v.empty() || v.back().first != s[i])
                v.emplace_back(s[i] , 1);
            else
                v.back().second++;
        }

        for (int i = 0 ; i + 1 < (int) v.size() ; ++i)
            ret += min(v[i].second , v[i + 1].second);

        return ret;
    }
};
