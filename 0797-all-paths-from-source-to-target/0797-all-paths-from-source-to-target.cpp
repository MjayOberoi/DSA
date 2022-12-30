class Solution {
public:
    void dfs(int current,vector<vector<int>> &res, vector<int> &r,vector<vector<int>>& graph){
        r.push_back(current);
        if(current == graph.size()-1){
            res.push_back(r);
        }
        else{
            for(auto it: graph[current]){
                dfs(it,res,r,graph);
                r.pop_back();
            } 
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> r;
        dfs(0,res,r,graph);
        return res;
    }
};