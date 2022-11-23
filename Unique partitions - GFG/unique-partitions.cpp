//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
    void solve(int index,vector<int> &ds,int tar,vector<vector<int>> &ans,vector<int> &arr){
	    
	    //base case
	    if(index==arr.size()){
	        if(tar==0){
	            ans.push_back(ds);
	        }
	        return;
	    }
	    
	    //rec case
	    if(arr[index]<=tar){
	        ds.push_back(arr[index]);
	        solve(index,ds,tar-arr[index],ans,arr);
	        ds.pop_back();
	    }
	  
	    solve(index+1,ds,tar,ans,arr);
	}
	
    vector<vector<int>> UniquePartitions(int n) {
        // Code here
        
        vector<vector<int>> res;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            arr[i] = n-i;
        }
        
        vector<int> ds;
        solve(0,ds,n,res,arr);
        
        return res;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		vector<vector<int>> ans = ob.UniquePartitions(n);
    	for(auto i : ans)
    		for(auto j: i)
    			cout << j <<" ";
    	cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends