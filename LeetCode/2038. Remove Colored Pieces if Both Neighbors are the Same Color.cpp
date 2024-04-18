class Solution {
public:
    bool winnerOfGame(string colors) {
        // Alice can make a move iff there is a sub-string
        // with length at least 3 with A's, considering this example
        // colors = "AAAAA" Alice can make 3 moves because he can't remove
        // the edges, we have a formula here, let's store the length of
        // the sub-string with A's only in a variable called "cnt"
        // and let "cntA" be the total number of moves Alice can make
        // so we can add to "cntA" max(0 , cnt - 2)
        // The same logic will be applied on Bob's case
        // Alice wins iff cntA > cntB

        int cntA = 0 , cntB = 0 , cnt = 0;

        // We need this variable to check if colors[i] = lst
        // and if so we increment cnt
        char lst = '0';

        // A lambda function that modifies cntA & cntB
        auto modify = [&]() {
            if (lst == 'A') cntA += max(0 , cnt - 2);
            else if (lst == 'B') cntB += max(0 , cnt - 2);
        };

        for (auto &c : colors) {
            if (c == lst) {
                ++cnt;
                continue;
            }

            // If we get here means c != lst, we got a sub-string of equal characters
            // we need to modify cntA or cntB
            modify();
            
            // reset cnt and lst 
            cnt = 1;
            lst = c;
        }

        // We may reach the end of the string without modifying
        modify();

        return cntA > cntB;
    }
};
