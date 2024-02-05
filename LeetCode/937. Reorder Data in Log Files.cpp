class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector < pair < string , string > > let;
        vector < string > dig;
        for (auto &s : logs) {
            int space_idx = s.find(' ');
            bool is_dig = false;
            for (int i = space_idx + 1 ; i < (int) s.size() ; ++i)
                is_dig |= isdigit(s[i]);
            if (is_dig) 
                dig.push_back(s);
            else {
                string letter = s.substr(space_idx + 1 , (int) s.size() - space_idx - 1);
                string id = s.substr(0 , space_idx + 1);
                let.push_back({letter , id});
            }
        }
        sort(let.begin() , let.end());
        vector < string > ret;
        for (auto [f , s] : let)
            ret.push_back(s + f);
        for (auto s : dig)
            ret.push_back(s);
        return ret;
    }
};
