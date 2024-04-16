class Solution {
public:
    int integerBreak(int n) {
        // we can try dynamic programming approach
        // we need to split the input i such a way we maximize
        // the product, if we try to imagine a recurion tree
        // the answer will like choosing a path from a root to a leaf node
        // in such a way if we multiply the values of the nodes we will get
        // the maximum product, but we need to consider the case k >= 2
        // this means the depth of our tree should be greater than zero
        
        // we need vector to save the answer of the current state lets call
        // it dp, dp[i] = the maximum product of the sub-problem n = i
        vector dp(n + 1 , vector < int > (2 , -1));
        
        return solve(n , 0 , dp);
    }

    // we need some boolean to indicate that we have splitted the number
    // if so, we can end and take the remaining as one number
    int solve(int n , bool isSplitted , vector < vector < int > > &dp) {
        if (n == 0) return 1;
        
        // memoization check
        auto &ret = dp[n][isSplitted];
        if (~ret) return ret;

        // the neutral answer is splitting the number with ones only
        ret = 1;

        // try all possible splits
        for (int i = 1 ; i <= (isSplitted ? n : n - 1) ; ++i)
            ret = max(ret , solve(n - i , 1 , dp) * i);
        
        return ret;
    }
};
