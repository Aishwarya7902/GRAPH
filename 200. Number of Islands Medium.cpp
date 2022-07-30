PROBLEM:                    https://leetcode.com/problems/number-of-islands/

BEST VIDEO EXPLAINATION:    https://youtu.be/UbzHYtUwKOY

/*APPROACH 1
tc:
sc:
FEEL :❤❤❤❤❤
1.grid me chalna suru karo( use 2 for loops for this)
2.moment u encounter a land do a count++ and call recursive function.....recursive function jitne bhi connected land hai un sabko pani me mila dega
i.e grid[i][j]=0   (connected lands pe jane ke liye use recursion)
3.the moment u come back from recursion .....repeat step 2 
4. at last return count ......itna simple to tha ye sawal bhai  😉
  */

class Solution {
public:
  bool isValid(int i,int j,int n,int m,vector<vector<char>>& grid){
   if(i>=0 && i<n && j>=0 && j<m && grid[i][j]=='1') 
   {
     return true;
   }
    return false;
  }
  
  
  void islandRec(int i,int j,int n,int m,vector<vector<char>>& grid){
      grid[i][j]='0';
      //left
      if(isValid(i-1,j,n,m,grid)){
          islandRec(i-1,j,n,m,grid);
      }
      //right
      if(isValid(i+1,j,n,m,grid)){
          islandRec(i+1,j,n,m,grid);
      }
      //up
      if(isValid(i,j-1,n,m,grid)){
          islandRec(i,j-1,n,m,grid);
      }
      //down
      if(isValid(i,j+1,n,m,grid)){
          islandRec(i,j+1,n,m,grid);
      }
    }
  
  
  int numIslands(vector<vector<char>>& grid) {
      int ans=0;
      int n=grid.size();
      int m=grid[0].size();
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          if(grid[i][j]=='1'){
            ans++;
            islandRec(i,j,n,m,grid);
          }
        }
      }
      return ans;
    }
};
