PROBLEM:https://leetcode.com/problems/number-of-enclaves/
VIDEO:https://youtu.be/saItFowXF4U

/*
TC:
SC:
*/
class Solution {
    private:
    //count function
    int Count(vector<vector<int>>& grid,int m,int n){
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
              if(grid[i][j]==1)
                  cnt++;
            }
        }
        return cnt;
    }
    //isValid function
    bool isValid(vector<vector<int>>& grid,int m ,int n,int i,int j){
        if(i>=0 && i<m && j>=0 && j<n && grid[i][j]==1)
            return true;
        return false;
    }
    
    //dfs function
    void dfs(vector<vector<int>>& grid,int m ,int n,int i,int j){
        grid[i][j]=0;
        //up
        if(isValid(grid,m,n,i-1,j))
            dfs(grid,m,n,i-1,j);
        //down
        if(isValid(grid,m,n,i+1,j))
            dfs(grid,m,n,i+1,j);
        //left
        if(isValid(grid,m,n,i,j-1))
            dfs(grid,m,n,i,j-1);
        //right
        if(isValid(grid,m,n,i,j+1))
            dfs(grid,m,n,i,j+1);
        
    }
public:
    
    
    
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        
        
        for(int i=0;i<m;i++){
            int j=0;
           //leftmost->top to bottom
          if(grid[i][j]==1)
              dfs(grid,m,n,i,j);
          //rightmost->top to bottom
            j=n-1;
            if(grid[i][j]==1)
              dfs(grid,m,n,i,j);  
            
        }
         
        
        
        
        for(int j=0;j<n;j++){
            //uppermost-> left to right
            int i=0;
          if(grid[i][j]==1)
              dfs(grid,m,n,i,j);
             //lowermost-> left to right
            i=m-1;
            if(grid[i][j]==1)
              dfs(grid,m,n,i,j);   
            
        }
       
        
        
        
      return  Count(grid,m,n);
    }
};

