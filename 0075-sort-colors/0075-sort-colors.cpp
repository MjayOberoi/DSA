class Solution {
public:
    void sortColors(vector<int>& nums) {
        int m=0, j=0, k=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0) m++;
            else if(nums[i]==1) j++;
            else if(nums[i]==2) k++;
        }
        int r=0;
        while(m>0){
            nums[r++] = 0;
            m--;
        }
        while(j>0){
            nums[r++] = 1;
            j--;
        }
        while(k>0){
            nums[r++] = 2;
            k--;
        }
    }
};