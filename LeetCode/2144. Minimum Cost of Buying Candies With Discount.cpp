class Solution {
public:
    int minimumCost(vector<int>& cost) {
        /*
            Assume we have a sorted array ascending, the purchasing approach goes like this:
            011011011....011, where 0 means you will get the candy for free.
            So the safest approach is to get the highest two to get the third for free.
        */

        // First, we need to sort the input array
        sort(cost.begin(), cost.end());

        int minCost = 0;

        // Last, As discussed before, start with maximum 2 values then take the third for free.
        // We need a variable to keep track how many candies sold.
        int sold = 0;
        while (!cost.empty()) {
            if (sold == 2) {
                // if sold = 2, we will get the current candy for free and set sold to zero
                cost.pop_back(); 
                sold = 0;
                continue;
            }
            // else you should buy the current candy.
            minCost += cost.back();
            ++sold;
            cost.pop_back();
        }

        return minCost;
    }
};
