//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
      long long ans = 0;
      int left = 0,right = n-1;
      int left_block = arr[0],right_block = arr[n-1];
       
        while(left<=right){
            if(left_block<right_block){
            
                if(arr[left]>left_block)
                left_block = arr[left];
            
                ans +=left_block-arr[left];
                left++;
                
            }else{
            
                if(arr[right]>right_block) 
                right_block = arr[right];
            
                ans+=right_block-arr[right];
                right--;
        }
     }
       return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends