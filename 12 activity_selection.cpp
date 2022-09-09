#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second<b.second;
}
int countActivites(vector<pair<int,int> > arr){
    //Complete this method
    sort(arr.begin(),arr.end(),cmp);
    int count = 1, j=0;
    for(int i=1;i<arr.size();i++){
        if(arr[i].first>=arr[j].second){
            count ++;
            j = i;
        }
    }
    return count;
}
