class Solution {
public:
    public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int initJumps = numRows * 2 - 2;
        int jumpSize = initJumps;
        string result;
        for (int i = 0; i < numRows; i++) {
            int j = i;
            bool goingDown = true;
            while (j < s.size()) {
                result += s[j];
                if (i == 0 || i == numRows - 1) j += initJumps;
                else j = goingDown ? j + jumpSize : j + (initJumps - jumpSize);
                goingDown = !goingDown;
            }
            jumpSize -= 2;
        }
        return result;
    }
};