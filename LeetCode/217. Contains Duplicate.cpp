class Solution {
public:
    bool containsDuplicate(vector<int>& a) {
        // we can store the input array in a hash set
        // if the size of the array isn't equal the size
        // of the set, this means there is at least one
        // element appear twice in the array
        unordered_set < int > s(a.begin() , a.end());
        return s.size() != a.size();
    }
};
