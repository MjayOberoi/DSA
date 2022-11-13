//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
typedef long long int ll;

class Solution{
public:
    int totalWays(int n, vector<int>capacity) {
        sort(capacity.begin(),capacity.end());
        ll res = 1;
        
        for(int i = 0 ; i < n ; i++){
            res = ((res)*((capacity[i]-i)))%1000000007;
        }
        return (int)res;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>capacity(n);
		for(int i = 0; i < n; i++)
			cin >> capacity[i];
		Solution ob;
		int ans = ob.totalWays(n, capacity);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends