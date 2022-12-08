class Solution {
public:
    int calculate(string& s) {
        int cur = 0, ans = 0, interimRes = 0;
        char prevOp = '+';
        s += "##";                                     // just ensures all processing happens in loop...else we need to write outside for the last number
        for(auto c : s)
            if(c == ' ') continue;
            else if(isdigit(c)) 
                cur = cur * 10 + (c-'0');
            else {
                if(prevOp == '*')                      // '*':  Case-1
                    interimRes *= cur;
                else if(prevOp == '/')                 // '/':  Case-1
                    interimRes /= cur;
                else                                   // '+' and '-':  Case-2
                    ans += interimRes,
                    interimRes = prevOp == '+' ? cur : -cur;
                prevOp = c;
                cur = 0;
            }

        return ans;
    }
};