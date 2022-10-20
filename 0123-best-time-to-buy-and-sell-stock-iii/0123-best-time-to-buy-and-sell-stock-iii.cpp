class Solution {
public:
    int helper(int index, int buy, int count, vector<int>& prices,int n, vector<vector<int>> &dp){
        if(index==n || count < 0) return 0;
        if(dp[index][buy] != -1) return dp[index][buy];
        int profit = 0;
        if(buy)
            profit = max(-prices[index]+helper(index+1,0,count,prices,n,dp),0+helper(index+1,1,count,prices,n,dp));
        else
            profit = max(prices[index]+helper(index+1,1,count-1,prices,n,dp),0+helper(index+1,0,count,prices,n,dp));
        return dp[index][buy]=profit;
    }
    
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
       
        for(int index=n-1;index>=0;index--){
            for(int buy=1;buy>=0;buy--){
                for(int cap=1; cap<=2;cap++){
                    int profit = 0;
                    if(buy==1)
                        dp[index][buy][cap] = max(-prices[index]+dp[index+1][0][cap],0+dp[index+1][1][cap]);
                    else
                        dp[index][buy][cap] = max(0+dp[index+1][0][cap],prices[index]+dp[index+1][1][cap-1]);
               }
            }
        }        
        return dp[0][1][2];
    }
};