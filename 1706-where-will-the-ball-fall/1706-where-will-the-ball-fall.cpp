class Solution {
public:
    int m,n;
    int solve(int r,int c,vector<vector<int>> &grid){
        if(r==m)return c;
        if(grid[r][c]==1){
            if(c+1>=n || grid[r][c+1]==-1)return -1;
            return solve(r+1,c+1,grid);
        }
        if(c-1<0 || grid[r][c-1]==1)return -1;
        return solve(r+1,c-1,grid);
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        vector<int> ans(n,-1);
        for(int c=0;c<n;c++){
            ans[c]=solve(0,c,grid);
        }
        return ans;
    }
};