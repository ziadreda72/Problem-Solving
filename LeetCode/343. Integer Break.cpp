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

/*
Time: O(n^2)
Space: O(n)
*/

//-------------------------------------------------------------------------------------------------------

class Solution {
public:
    int integerBreak(int n) {
        // We've just seen how to solve this problem is a recursive
        // way and then how to optimize it using memoization trick
        // but the most efficient way is to use buttom-up dynamic programming
        // we know already the answer of the base case n = 1, which is one
        // the idea is we can build on the top of that and get the answer, but how?
        // if we try to solve the sub-problem i = 2, we will see there are two cases
        // first is n = 2, we can't say that the answer is 2 because k should be >= 2
        // so the only option we have is to split it with two ones
        // second n > 2, we can say that the answer for this sub-problem is 2, why?
        // because we only intrested in finding the answer for n, and if n = 4 for example
        // we can split it with two twos so dp[4] = dp[2] * dp[2] which is 4
        // so the transition state will be dp[i] = max(dp[i] , dp[j] * dp[i - j])
        // where i is the current sub-problem and j is the number we will split using it

        // we need a dp table to save the answer for each sub-problem
        vector < int > dp(n + 1 , 0);

        dp[1] = 1;
        for (int i = 2 ; i <= n ; ++i) {
            // The neutral answer for the sub-problem is not to split anymore
            // we can't do that with i == n because the condition k >= 2
            if (i < n) dp[i] = i;
            for (int j = 1 ; j < i ; ++j)
                dp[i] = max(dp[i] , dp[j] * dp[i - j]);
        }

        return dp.back();
    }
};

/*
Time: O(n^2)
Space: O(n)
*/
