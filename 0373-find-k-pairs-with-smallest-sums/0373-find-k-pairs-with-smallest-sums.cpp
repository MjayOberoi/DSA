class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>ans;
        for(int i=0;i<nums1.size();i++)
        {
            pq.push({nums1[i]+nums2[0],{i,0}});
        }
        while(!pq.empty() and ans.size()<k)
        {
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            if(j<nums2.size()-1)
            {
                pq.push({nums1[i]+nums2[j+1],{i,j+1}});
            }
            ans.push_back({nums1[i],nums2[j]});
        }
        return ans;
    }
};