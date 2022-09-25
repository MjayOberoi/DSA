#include<iostream>
#include <vector>
using namespace std;

//helper method
int merge(vector<int> &array,int s,int e){
        int i = s;
        int m = (s+e)/2;
        int j = m + 1;

        vector<int> temp;

        int cnt = 0;

        while(i<=m and j<=e){
          if(array[i] < array[j]){
            temp.push_back(array[i]);
            i++;
          }
          else{
            cnt += (m - i + 1);
            temp.push_back(array[j]);
            j++;
          }
        }

        //copy rem elements from first array
        while(i<=m){
          temp.push_back(array[i++]);
        }

        // or copy rem elements from second array
        while(j<=e){
          temp.push_back(array[j++]);
        }

        //copy back the eleemtns from temp to original array
        int k = 0 ;
        for(int idx = s; idx <=e ;idx++){
          array[idx] = temp[k++];
        }
        return cnt;
}

//sorting method
int inversion_count(vector<int> &arr,int s,int e){
        //base case
        if(s>=e){
          return 0;
        }
        //rec case
        int mid = (s+e)/2;
        int C1 = inversion_count(arr,s,mid);
        int C2 = inversion_count(arr,mid+1,e);
        int CI =  merge(arr,s,e);
        return C1 + C2 + CI;
}

int main(){
  	
        vector<int> arr{0,5,2,3,1};

        int s = 0;
        int e = arr.size()-1;
          cout<< inversion_count(arr,s,e) <<endl;

        cout<<endl;
        return 0;
}
------------------------------------------------------------------------------------------------------------------------------------------------------
class Solution{
public:
 long long int conquer(long long  arr[],long long  lo,long long  mid,long long  hi){
         long long  n1 = mid-lo+1;
         long long  n2 = hi-mid;
         long long  a[n1],b[n2];
         
         for(long long  i=0;i<n1;i++) a[i] = arr[lo+i];
         for(long long  i=0;i<n2;i++) b[i] = arr[mid+1+i];
         
         long long  p=0,q=0,k=lo;
         long long int inv=0;
         
         while(p<n1 and q<n2){
                if(a[p]<=b[q]) arr[k++] = a[p++];
                else{
                      inv+=(n1-p);
                      arr[k++] = b[q++];
                }  
         }
         while(p<n1) arr[k++] = a[p++];
         while(q<n2) arr[k++] = b[q++];
         return inv;
   }
   
   long long int divideNconquer(long long arr[],long long  lo,long long  hi){
          long long ans = 0;
          if(lo<hi){
                long long  mid = lo + (hi-lo)/2;
                ans+=divideNconquer(arr,lo,mid);
                ans+=divideNconquer(arr,mid+1,hi);
                ans+=conquer(arr,lo,mid,hi);
          }
          return ans;
   }
   
   long long int inversionCount(long long arr[], long long N){
       return divideNconquer(arr,0,N-1);
       // Your Code Here
   }
};

