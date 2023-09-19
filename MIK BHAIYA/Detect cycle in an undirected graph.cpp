PROBLEM:https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

/*
  TC:O(V+E)
  SC:O(V+E)
  since we are rusing dfs
*/

class Solution {
  public:
    bool isCycleDfs(vector<int> adj[],int u,vector<bool>&visited,int parent){
        
        visited[u]=true;
        for(int &v:adj[u]){
            if(v==parent)continue;
            if(visited[v]==true)return true;
            if(isCycleDfs(adj,v,visited,u))return true;
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i] && isCycleDfs(adj,i,visited,-1)){
                return true;
            }
        }
        
        return false;
    }
};
