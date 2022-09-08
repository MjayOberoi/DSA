//Product of Array Except Self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int fromBegin=1;
        int fromLast=1;
        vector<int> res(n,1);
        
        for(int i=0;i<n;i++){
            res[i]*=fromBegin;
            fromBegin*=nums[i];
            res[n-1-i]*=fromLast;
            fromLast*=nums[n-1-i];
        }
        return res;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n,1);
        vector<int> prefix(n,1);
        vector<int> suffix(n,1);
        
        for(int i=1;i<n;i++){
            prefix[i] = nums[i-1]*prefix[i-1];
        }
        //suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i] = nums[i+1]*suffix[i+1];
        }
        
        // for(int i=0;i<n;i++){
        //     cout<<prefix[i] <<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<suffix[i] <<" ";
        // }
        // cout<<endl;
        
        for(int i=0;i<n;i++){
            output[i]= prefix[i]*suffix[i];
        }
        return output;
    }
};
