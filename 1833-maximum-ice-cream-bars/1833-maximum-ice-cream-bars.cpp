class Solution {
public:
    int maxIceCream(vector<int>& cost, int coins) {
        sort(cost.begin(), cost.end());
        int res = 0;
        for(int i=0; i<cost.size(); i++){
            if(coins >= cost[i]){
                res++;
                coins -= cost[i];
            }
        }
        return res;
    }
};