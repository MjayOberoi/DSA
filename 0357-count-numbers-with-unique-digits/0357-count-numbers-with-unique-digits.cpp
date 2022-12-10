class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        if(n==1) return 10;
        if(n==2) return 91;
        
        int count=91,digits=81;
        
        for(int i=3;i<=n;i++){
            count+=(digits*=(10-i+1));
        }
        
        return count;
    }
};