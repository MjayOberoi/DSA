//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int numberOfSubsequences(string S, string W){
        int w = 0;
        for(int i=0; i<S.size(); i++)
        {
            if(S[i] == W[w]){
                w++;
                S[i] = ' ';
            }
            if(w == W.size()) break;
        }
        
        if(w == W.size()) 
        return 1 + numberOfSubsequences(S , W);
        return 0; 
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends