//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> satisfyEqn(int A[], int N) {
        unordered_map<int,pair<int,int>> mp;
        set<vector<int>> ans;
        
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                if(mp.find(A[i]+A[j])!=mp.end())
                {
                    int ind1 = mp[A[i]+A[j]].first;
                    int ind2 = mp[A[i]+A[j]].second;
                    if(i!=ind2 && i!=ind1 && j!=ind2 && j!=ind1)
                    {
                        ans.insert({ind1,ind2,i,j});
                    }
                }
                mp.insert({A[i]+A[j],{i,j}});
            }
        }
        
        if(ans.size()==0) return {-1,-1,-1,-1};
        
        return *ans.begin();
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A,N);
        
        cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3]<<endl;
    }
    return 0;
}
// } Driver Code Ends