//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int k=-1;
        for(int j=0;j<n;j++){
            if(M[0][j]==1 || M[1][j]==1){
                int count = 0, i=0;
                while(i<n){
                    if(M[i][j]==1) count++;
                    i++;
                }
                if(count==n-1) k = j;
            }
        }
        if(k==-1) return -1;
        for(int p=0; p<n;p++){
            if(M[k][p] != 0) return -1;
        }
        return k;
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
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends
