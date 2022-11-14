//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    vector<int> res;
    int fo=-1, lo=-1;
    
    for(int i=0; i<n ;i++){
        if(arr[i]==x){
            lo = i;
            if(fo == -1) fo=i;
        }
    }
    res.push_back(fo);
    res.push_back(lo);
    return res;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends