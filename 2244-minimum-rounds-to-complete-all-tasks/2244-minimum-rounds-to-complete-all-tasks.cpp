class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        sort(tasks.begin(),tasks.end());
        map<int,int>m;
        for(int i = 0 ; i < tasks.size() ; i++){
            m[tasks[i]]++;
        }
        int count=0;
        for(auto i:m){
            if(i.second<2) return -1;
            else{
                float gg=i.second;
                gg = ceil(gg/3);
                
                count+=gg;
            }
        }
        return count;
    }
};