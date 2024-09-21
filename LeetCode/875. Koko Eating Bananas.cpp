class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        /*
            We can solve this problem with binary search on the answer, but why?
            because if Koko can finish all the bananas with speed k, surely he can finish them with speed of k + 1
            and if he can't finish them with speed k, he can't finish them with speed k - 1.
        */

        long long lo = 0, hi = *max_element(piles.begin(), piles.end());
        while (hi - lo > 1) {
            long long mid = (lo + hi) / 2;
            if (good(piles, h, mid))
                hi = mid;
            else
                lo = mid;
        }

        // answer is the value hi, as it's the first good value
        return hi;
    }

    bool good(vector < int > &piles, int &h, long long &k) {
        long long hours = 0;
        for (auto &pile : piles) {
            // to eat current pile you need pile / k rounded up
            hours += (pile + k - 1) / k;
        }

        return hours <= h;
    }
};
