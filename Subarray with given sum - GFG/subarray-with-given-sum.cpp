//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        vector<int> prefix (n+1,0);
        int sum=0;
        
        for(int i=0; i<n; i++){
            sum += arr[i];
            prefix[i+1] = sum;
        }
        int l=0, m= 1;
        while(m<=n){
            long long check = prefix[m]-prefix[l];
            if(check == s){
                return {l+1,m};
            }
            else if (check < s){
                m++;
            }
            else if ( check > s){
                l++;
            }
            if(l==m) m++;
        }
        return {-1};
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends