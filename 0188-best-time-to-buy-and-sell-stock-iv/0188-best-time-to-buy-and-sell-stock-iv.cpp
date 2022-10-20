class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> ahead(2,vector<int>(k+1,0));
        vector<vector<int>> cur(2,vector<int>(k+1,0));
        for(int index=n-1;index>=0;index--){
            for(int buy=1;buy>=0;buy--){
                for(int cap=1; cap<=k;cap++){
                    int profit = 0;
                    if(buy==1)
                        cur[buy][cap] = max(-prices[index]+ahead[0][cap],0+ahead[1][cap]);
                    else
                        cur[buy][cap] = max(0+ahead[0][cap],prices[index]+ahead[1][cap-1]);
               }
            }
            ahead = cur ;
        }        
        return ahead[1][k];
    }
};