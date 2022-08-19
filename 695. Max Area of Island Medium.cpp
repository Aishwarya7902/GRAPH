class Solution {
public:
   bool isValid(vector<vector<int>>& grid,int i,int j,int m,int n){
       if(i>=0 && i<m && j>=0 && j<n && grid[i][j]==1)
           return true;
       return false;
   }
   int dfs(vector<vector<int>>& grid,int i,int j,int m,int n){
       grid[i][j]=0;
       int left=0,right=0,up=0,down=0;
        if(isValid(grid,i-1,j,m,n)){
             left=dfs(grid,i-1,j,m,n);
        }
        if(isValid(grid,i+1,j,m,n)){
            right=dfs(grid,i+1,j,m,n);
        }
        if(isValid(grid,i,j-1,m,n)){
            up=dfs(grid,i,j-1,m,n);
        }
        if(isValid(grid,i,j+1,m,n)){
            down=dfs(grid,i,j+1,m,n);
        }
       return 1+left+right+up+down;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
       int m=grid.size();
        int n=grid[0].size();
       int ans=INT_MIN;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                   ans=max(ans,dfs(grid,i,j,m,n));
                }
            }
        }
        return (ans==INT_MIN) ? 0 : ans;
    }
};
