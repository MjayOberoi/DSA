//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        int largestArea(int n,int m,int k,vector<vector<int>> &a)
        {
            unordered_set<int> x, y;
    //blocked values are geeting inserted
            for(int i=0; i<k; i++) {
                x.insert(a[i][0]);
                y.insert(a[i][1]);
            }
    //since m and n have different value hence needs 2 for loop
            int r = 0, c = 0, count = 0;
            for(int i=1; i<=n; i++) {
            // the value is not in set means that it is not blocked
                if(x.find(i) == x.end()) count++;
                else {
            //finding the maximum unblocked length 
                    r = max(count, r);
            //setting the count to again 0 as now the current value is in set implying that it is blocked
                    count = 0;
                }
            }
    //taking the max value of count again bcz what if last value is not in set then it will not go in else block
            r = max(count, r);
        
            count = 0;
            for(int i=1; i<=m; i++) {
                if(y.find(i) == y.end()) count++;
                else {
                    c = max(count, c);
                    count = 0;
                }
            }
            c = max(count, c);
            
            return k==0 ? (n*m) : (r*c);
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        vector<vector<int>> e(k,vector<int>(2));
        for(int i=0;i<k;i++)
            cin>>e[i][0]>>e[i][1];
        Solution a;
        cout<<a.largestArea(n,m,k,e)<<endl;
    }
    return 0;
}
// } Driver Code Ends