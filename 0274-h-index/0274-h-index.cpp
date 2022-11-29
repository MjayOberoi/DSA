class Solution {
public:
    int hIndex(vector<int>& cit) {
        sort(cit.begin(),cit.end());
        int n=cit.size(),count=0;
        for(int i=n-1;i>=0;i--)
        {
            if(n-i<=cit[i])
                count++;
        }
        return count;
    }
};