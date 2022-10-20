class Solution {
public:
    int solve(int index, int flag, vector<int> &prices, int n, vector<vector<int>> &dp){
        if(index==n) return 0;
        if(dp[index][flag] != -1) return dp[index][flag];
        int profit=0;
        
        if(flag==1){
            profit = max(-prices[index]+solve(index+1,0,prices,n,dp),0+solve(index+1,1,prices,n,dp));
        }
        else{
            profit = max(prices[index]+solve(index+1,1,prices,n,dp),0+solve(index+1,0,prices,n,dp));
        }
        return dp[index][flag]=profit;
    }
    
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>> dp (n+1, vector<int>(2,-1));
        
        dp[n][0] = dp[n][1] = 0;
        for(int index=n-1;index>=0;index--){
            for(int flag=0;flag<=1;flag++){
                
                int profit=0;
                if(flag==1){
                    profit = max(-prices[index]+dp[index+1][0],0+dp[index+1][1]);
                }
                else{
                    profit = max(prices[index]+dp[index+1][1],0+dp[index+1][0]);
                }
                dp[index][flag] = profit;
            }
        }
        
        return dp[0][1];
            
    }
};