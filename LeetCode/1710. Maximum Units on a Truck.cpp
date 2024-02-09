class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        for (int i = 0 ; i < (int) boxTypes.size() ; ++i)
            swap(boxTypes[i][0] , boxTypes[i][1]);

        sort(boxTypes.begin() , boxTypes.end());

        int ret = 0;
        while (boxTypes.size() && truckSize) {
            boxTypes.back()[1] = min(boxTypes.back()[1] , truckSize);
            ret += boxTypes.back()[1] * boxTypes.back()[0];
            truckSize -= boxTypes.back()[1];
            boxTypes.pop_back();
        }

        return ret;
    }
};
