class Solution {
public:
    int numDecodings(string s) {
        /*
            This problem can be easily solved with Top-Down DP (Recursion with Memoization).
            There are two option to build a character if we are at index i:
            First: just take s[i] and check it's not a zero
            Second: take s[i] and s[i + 1] if i + 1 still in the string bounds, in this case
            we need to check that there are no leading zeros and the built number between [1, 26]
            The answer is to count the number of ways we can reach the end of the string. 
        */

        n = (int) s.size();

        // This vector dp is to memoize the answer of the sub-problem
        // if dp[i] = -1, means this sub-problem is not solved yet
        vector < int > dp(n + 5 , -1);

        int ret = solve(0 , s , dp);
        return ret;
    }

    int solve(int i , string &s ,vector < int > &dp) {
        if (i >= n) {
            // we managed to decode the message so we add one to the answer
            return 1; 
        }

        // check memo table to avoid solving the same sub-problem twice
        if (dp[i] != -1)
            return dp[i];

        // We are solving this sub-problem now 
        // with initial value zero as we haven't reached a solution yet
        dp[i] = 0;

        // check a single character string
        if (s[i] != '0')
            dp[i] += solve(i + 1 , s , dp);

        // check two characters string
        if (s[i] != '0' && i + 1 < n) {
            if (check(s.substr(i , 2)))
                dp[i] += solve(i + 2 , s , dp);
        }

        return dp[i];
    }

    bool check(string s) {
        int x = stoi(s);
        return (1 <= x && x <= 26);
    }

private:
    int n;
};

----------------------------------------------------------------------------------------------------------------------------------------------------

class Solution {
public:
    int numDecodings(string s) {
        /*
            Now let's solve it with Bottom-Up DP.
            Assume you are at index i and s[i] != 0, there are two cases:
            First, take s[i] only and add dp[i] to dp[i + 1]
            Second, take s[i + 1] also if i + 1 inside of string boarder
            and add dp[i] to dp[i + 2].
            The answer will be in dp[n].
        */

        int n = (int) s.size();

        // Now we need a dp array to save the answer of sub-problems
        vector < int > dp(n + 1 , 0);

        // Base Case: dp[0] = 1 if s[0] != 0
        dp[0] = s[0] != '0';

        // Now start building the answer of sub-problems
        for (int i = 0 ; i < n ; ++i) {
            if (s[i] != '0') {
                dp[i + 1] += dp[i];

                // Now we need to check that s[i]s[i + 1] between [1 , 26]
                int x = stoi(s.substr(i , 2));
                if (i + 1 < n && (1 <= x && x <= 26))
                    dp[i + 2] += dp[i];
            }
        }

        // Answer is dp[n];
        return dp[n];
    }
};

/*
    Time: O(n)
    Space: O(n)
*/
