//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    queue<char> q;
		    unordered_map<char,int> mp;
		    string ans = "";
		    
		    for(int i=0; i<A.length(); i++){
		        mp[A[i]]++;
		        if(mp[A[i]]==1) q.push(A[i]);
		        char check = q.front();
		        while(mp[check] != 1 and !q.empty()){
		            q.pop();
		            check = q.front();
		        }
		        if(q.empty()) ans += '#';
		        else ans += check;
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends