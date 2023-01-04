class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int counter = 0;
        for(int i=0; i<=strs[0].size(); i++) {
            string currStr = "";
            string sortedStr = "";
            
            for(int j=0; j<strs.size(); j++) {
                currStr += strs[j][i];
                sortedStr += strs[j][i];
            }
            sort(sortedStr.begin(), sortedStr.end());
            if (sortedStr != currStr) counter ++;
        }
        return counter;
    }
};