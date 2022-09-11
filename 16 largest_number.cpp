bool cmp(string &s1, string &s2){
        return s1+s2>s2+s1;
    }
class Solution {
public:
    
    string largestNumber(vector<int>& nums) {
        vector<string>arr;
        for(auto num :nums) arr.push_back(to_string(num));
        sort(arr.begin(),arr.end(),cmp);
        string res="";
        for(auto s: arr) res+= s;
        if(res[0]=='0') res="0";
        return res;
    }
};
