
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> um;
        int i=0,count=0,mx=0;
        while(i<s.length()){
            if(um.count(s[i])== 0){
                um[s[i]]=i;
                count++;
                mx = max(mx,count);
            }
            else{
                int temp = i-um[s[i]];
                if(temp<=count) count = temp;
                else count++;
                mx = max(mx,count);
                um[s[i]]=i;
            }
            i++;
        }
        return mx;
        
    }
};
