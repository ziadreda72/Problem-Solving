class Solution {
public:
    Solution(vector<int>& w) {
        /*
            Let's assume we have a bigger array called "rep" of size "W", where W = sum(w)
            we can translate the meaning of "w[i]" to: index "i" is going to be repeated w[i] times in "rep"
            if we have w = [1, 2, 3] and we are assuming "rep" is 0-indexed too, "rep" will be like:
            idx: 0 1 2 3 4 5
            rep: 0 1 1 2 2 2
            assuming we have a function that picks a number at random from the interval [0, W) called "j"
            the problem now is to return the value of "rep[j]".
            Due to large input size we can't build the array "rep" because of the space complexity O(W) which is ~ 1e9.
            Back to the original problem, let's build an array closer to the concept of prefix sums, let's call it "sum"
            which sum[0] = 0 and sum[i] is the some of all w[j] where j < i for all i > 0, so if w = [1, 2, 3]
            sum = [0, 1, 3], back to "rep" array, if the random number "j" is revealed, we can see that: 
            index 0 will be returned if j in the interval [0, 1)
            inedx 1 will be returned if j in the interval [1, 3)
            index 2 will be returned if j in the interval [3, 6)
            we can see that the starting of the interval is the array "sum".
            The problem is simplified to a binary search problem "What is the upper bound of the chosen number j"
        */

        // build array "sum"
        int prev_sum = 0;
        for (int i = 0 ; i < (int) w.size() ; ++i) {
            sum.push_back(prev_sum);
            prev_sum += w[i];
        }

        // prev_sum now holds the sum of the array "w"
        W = prev_sum;
    }
    
    int pickIndex() {
        // pick some random number j
        int j = rand() % W;

        // if the upper bound is index i, our answer is the index before i
        int i = upper_bound(sum.begin() , sum.end() , j) - sum.begin();

        return i - 1;
    }

private:
    vector < int > sum;
    int W;
};

/**
 * Time: O(nlog(n))
 * Space: O(n)
 */
