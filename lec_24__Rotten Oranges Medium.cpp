PROBLEM: https://leetcode.com/problems/rotting-oranges/
VIDEO:   https://youtu.be/yf3oUhkvqA0

/*
approach 1:
tc: O(mxn) + O(mxn*4)coz for every guy u r running in all four directions....so it can be aggregated to O(mxn) only
sc:O(mxn)
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       int n=grid.size();
        int m=grid[0].size();
        int vis[n][m];  //space of O(mxn)
        //{{r,c},t}
      
        queue<pair<pair<int,int>,int>>q; //space of O(mxn)
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else{
                    vis[i][j]=0;
                }
                
            }
        }
        int tm=0;
        int drow[]={-1,0,+1,0};
        int dcol[]={0,-1,0,+1};
        
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            tm=max(tm,t);
            
            for(int i=0;i<4;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1
                && vis[nrow][ncol]!=2){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=2;
                    
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=2 && grid[i][j]==1)return -1;
            }
        }
        return tm; 
    }
};




/*same approach but a bit different logic*/
class Solution {
public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int vis[n][m];
        int cntfresh=0;
        //{{r,c},t}
        queue<pair<pair<int,int>,int>>q;
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                
                else{
                    vis[i][j]=0;
                }
                if(grid[i][j]==1)cntfresh++;
                
            }
        }
        int tm=0;
        int drow[]={-1,0,+1,0};
        int dcol[]={0,-1,0,+1};
        int cnt=0;
        
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            tm=max(tm,t);
            
            for(int i=0;i<4;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1
                && vis[nrow][ncol]!=2){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=2;
                    cnt++;
                }
            }
        }
       if(cntfresh!=cnt)return -1;
        return tm;
    }
};
