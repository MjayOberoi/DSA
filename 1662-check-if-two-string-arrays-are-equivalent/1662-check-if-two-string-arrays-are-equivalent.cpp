class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a = "";
        for(string s: word1) a += s;
            
        string b = "";
        for(string s: word2) b += s;
            
        if (a==b) return true;
        
        return false;
    }
};