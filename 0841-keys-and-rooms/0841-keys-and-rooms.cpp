class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int s,vector<int> &vis){
        vis[s]=1;
        int m = rooms[s].size();
        for(int i=0; i<m; i++){
            if(vis[rooms[s][i]]==0) 
                dfs(rooms,rooms[s][i],vis);
        }
    }
    
    
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n,0);
        dfs(rooms,0,vis);
        for(int i=0; i<n; i++){
            if(vis[i] != 1) return false;
        }
        return true;
    }
};