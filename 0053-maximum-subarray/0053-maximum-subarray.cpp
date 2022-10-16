class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int sum=0, max_sum = INT_MIN;
        
        for(int i=0; i<arr.size(); i++){
            sum += arr[i];
            max_sum = max(sum,max_sum);
            if(sum < 0){
                sum = 0;
            }
        }
        return max_sum;
    }
};