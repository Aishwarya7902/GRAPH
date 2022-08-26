PROBLEM:https://leetcode.com/problems/number-of-provinces/
VIDEO:https://www.youtube.com/watch?v=W3YyfjxKcA0&list=PLzjZaW71kMwSrxEtvK5uQnfNQ9UjGGzA-&index=26

/*APPROACH1
In this prroblem besically we need to count the number of connected componets.
So for that i converted the input matrix in a adjacency list then I run a dfs on them
TC:
SC:
*/

class Solution {
public:
    void dfs(int s,vector<int> adj[],vector<bool>&visited){
     visited[s]=true;
        //
        for(auto u:adj[s]){
            
               if(!visited[u])
                dfs(u,adj,visited);
        }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
       int n= isConnected.size(); 
       vector<bool>visited(n+1,false);
       vector<int> adj[209];
       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
              
               if(isConnected[i][j]==1){
                   adj[i].push_back(j);
                   
               }
           }
       }
       
        int cnt=0;
       for(int i=0;i<n;i++){
           if(!visited[i]){
           
           dfs(i,adj,visited);
               cnt++;
           }
       }
 return cnt;
    }
};
