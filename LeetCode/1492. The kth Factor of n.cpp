class Solution {
public:
    int kthFactor(int n, int k) {
        int tot = 0;
        for(int d = 1 ; d * d <= n ; ++d){
            if(n % d == 0){
                tot++;
                tot += (d != n / d);
            }
        }
        int cur = 0;
        for(int d = 1 ; d * d <= n ; ++d){
            if(n % d == 0){
                cur++;
                if(cur == k) return d;
                if(tot - cur + 1 == k) return n / d;
            }
        }
        return -1;
    }
};
