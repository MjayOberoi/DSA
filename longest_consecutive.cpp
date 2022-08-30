class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count = 1;
        int res = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                count ++;
                res = max(res,count);
            }
            else if(nums[i]==nums[i-1]){
                continue;
            }
            else count = 1;
        }
        return nums.size()>=1?res:0;
    }
};
