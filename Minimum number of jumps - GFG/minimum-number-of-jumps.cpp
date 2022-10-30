//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        int curr=0, reach=0, ans=0;
        
        while(reach < n-1){
            int far = 0;
            for(int i=curr; i<=reach; i++) far=max(far, i+arr[i]);
            
            if (far==0) return -1;
            curr = reach+1;
            reach = far;
            ans++;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends