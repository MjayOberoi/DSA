//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimizeSum(int n, vector<int> v) {
        sort(v.begin(),v.end());
        int ans = 0;
        while(v.size()>1){
            int x = v[0] + v[1];
            ans +=x;
            v.erase(v.begin());
            v.erase(v.begin());
            v.insert(lower_bound(v.begin(),v.end(),x),x);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minimizeSum(n, arr) << "\n";
    }
}
// } Driver Code Ends