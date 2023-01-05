class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& arr){
        int n=arr.size(),count=0,temp;
        sort(arr.begin(),arr.end());
        temp=arr[0][1];

        for(int i=0;i<n;i++){
            if(arr[i][0]>temp){
                count++;
                temp=arr[i][1];
            }
            temp=min(arr[i][1],temp);
        }
        return count+1;
    }
};