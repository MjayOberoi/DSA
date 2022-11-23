//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	vector<int> lis(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        for(int i=0;i<nums.size();i++)
            for(int p=0;p<i;p++)
                if(nums[i]>nums[p]) 
                dp[i]=max(dp[i],1+dp[p]);
        return dp;
    }
	
	int LongestBitonicSequence(vector<int>nums)
	{
	    vector<int> dp1=lis(nums);
	    reverse(nums.begin(),nums.end());
	    vector<int> dp2=lis(nums);
	    int maxi=INT_MIN;
	    for(int i=0;i<nums.size();i++)
	        maxi=max(maxi,dp1[i]+dp2[nums.size()-i-1]-1);
	    return maxi;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends