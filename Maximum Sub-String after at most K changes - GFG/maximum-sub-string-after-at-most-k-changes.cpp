//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int characterReplacement(string s, int k){
		    int i=0, j=0, max_cnt=0, ans=0;
		    unordered_map<char,int> um;
		    
		    while(j<s.length()){
		        um[s[j]]++;
		        max_cnt = max(max_cnt, um[s[j]]);
		        j++;
		        if(j-i-max_cnt>k){
		            um[s[i]]--;
		            i++;
		        }
		        ans = max(ans,j-i);
		    }
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends