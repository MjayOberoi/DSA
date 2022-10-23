class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i,j, hi=nums.size()-1;
        
        for( i=hi-1; i>=0; i--){
            if(nums[i+1]>nums[i]) break;
        }
        
        if(i>=0){
            for(j=hi; j>i; j--){
                if(nums[j]>nums[i]){
                    swap(nums[j],nums[i]);
                    break;
                }
            }
        }
        reverse(nums.begin()+i+1,nums.end());
    }
};