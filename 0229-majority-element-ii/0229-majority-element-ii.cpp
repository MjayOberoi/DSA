class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

     // declared a vector ans
     vector<int> ans;
     
    // declared a variable temp and assigned it the value size/3 
     int temp=nums.size()/3;

    // using hashing found out the frequency of all the elements 
     unordered_map<int,int> mp;
     for(int i=0;i<nums.size();++i){
         mp[nums[i]]++;
     }   

     for(auto i:mp){
         /* if frequency > size/3 then push back the element into     vector ans */ 
         if(i.second>temp){
             ans.push_back(i.first);
         }
     }
     return ans;
    }
};