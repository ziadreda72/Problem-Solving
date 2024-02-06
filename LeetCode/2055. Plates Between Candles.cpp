class Solution {
public:
    vector<int> pos; // positions of candles

    // A function that returns the index of the first candle in the
    // left of position x
    int L(int x) {
        int lo = -1, hi = (int)pos.size();
        while (hi - lo > 1) {
            int mid = (lo + hi) / 2;
            if (pos[mid] <= x)
                lo = mid;
            else
                hi = mid;
        }
        return lo;
    }

    // A lamda function that return s the index of the first candle int the
    // right of position x
    int R(int x) {
        int lo = -1, hi = (int)pos.size();
        while (hi - lo > 1) {
            int mid = (lo + hi) / 2;
            if (pos[mid] >= x)
                hi = mid;
            else
                lo = mid;
        }
        return hi;
    }

    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = (int)s.size();

        for (int i = 0; i < n; ++i)
            if (s[i] == '|')
                pos.push_back(i);

        vector<int> pref_sum(n, 0);
        for (int i = 1; i < n; ++i)
            pref_sum[i] = pref_sum[i - 1] +
                          (s[i] == '*' && L(i) > -1 && R(i) < (int)pos.size());

        vector<int> ret;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            int lo = R(l), hi = L(r);
            if (lo == (int)pos.size() || hi == -1 || hi < lo)
                ret.push_back(0);
            else {
                int sum = pref_sum[pos[hi]] -
                          (pos[lo] == 0 ? 0 : pref_sum[pos[lo] - 1]);
                ret.push_back(sum);
            }
        }

        return ret;
    }
};
