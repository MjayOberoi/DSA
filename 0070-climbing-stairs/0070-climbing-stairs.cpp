class Solution {
public:
    int climbStairs(int n) {
        int w1 = 1, w2 = 0, tmp;
        for (int i = 0; i < n; ++i)
            tmp = w1, w1 += w2, w2 = tmp;
        return w1;
    }
};