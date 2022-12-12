class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int>m;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
        }
        for(auto it:m)
        {
            if(m.find(1)==m.end())
                return 1;
        }
        for(int i=1;i<n+2;i++)
        {
            if(m.count(i)==0)
                return i;
        }
        // return nums[n-1]+1;
        return 1;
    }
};