//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string ct[], string s)
    {
        map <string, int> mp;
        for(int i=0;i<n;i++) mp[ct[i]]++;
        
        vector<vector<string>> res;
        for(int i=0;i<s.length();i++){
            vector <string> temp;
            for(auto it: mp){
                if(it.first.substr(0,i+1)==s.substr(0,i+1)) temp.push_back(it.first);
            }
            if(temp.size()==0) temp.push_back("0");
            res.push_back(temp);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends