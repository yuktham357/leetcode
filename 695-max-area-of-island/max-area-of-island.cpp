class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int maxarea=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    int curr=dfs(i,j,grid,vis);
                    maxarea=max(maxarea,curr);
                }
            }
        }
        return maxarea;
    }
    int dfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>&vis){
        vis[i][j]=true;
        vector<int>dr={1, 0, 0,-1,};
        vector<int>dc={0, -1, 1,0};
        int count=1;
        for(int k=0;k<4;k++){
            int r=i+dr[k];
            int c=j+dc[k];
            if(issafe(r,c,grid,vis)){
                if(!vis[r][c]){
                    count=count+dfs(r,c,grid,vis);
                }
            }
        }
        return count;
    }
    bool issafe(int r,int c,vector<vector<int>>& grid,vector<vector<bool>>& vis){
        int n=grid.size();
        int m=grid[0].size();
        return (r>=0 && r<n && c>=0 && c<m && grid[r][c]==1);
    }
};