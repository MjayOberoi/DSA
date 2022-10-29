class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<int> indices(plantTime.size());
       // for(auto i: indices) cout<<i<<" ";
        iota(indices.begin(), indices.end(), 0);
        // for(auto i: indices) cout<<i<<" ";
        sort(indices.begin(), indices.end(),
             [&](int i, int j) { return growTime[i] > growTime[j]; });
        
        
        int result = 0, curPlantTime = 0;
        for (int i : indices) {
           // cout<<i<<",";
            curPlantTime += plantTime[i];
            result = max(result, curPlantTime + growTime[i]);
        }
        return result;
    }
};