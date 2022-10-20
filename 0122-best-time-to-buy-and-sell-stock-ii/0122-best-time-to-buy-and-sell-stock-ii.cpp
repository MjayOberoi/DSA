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
        
        vector<vector<int>> dp (n, vector<int>(2,-1));
        
        return solve(0,1,prices,n, dp);
            
    }
};