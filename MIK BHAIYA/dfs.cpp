//PROBLEM:https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
class Solution {
  public:
     //helper function
     void dfsHelper(vector<int> adj[],int u,vector<bool>&visited,vector<int>&result){
       
         visited[u]=true;
         result.push_back(u);
        //explore
        
        
        for(int &v:adj[u]){
            if(!visited[v])
             dfsHelper(adj,v,visited,result);
        }
     }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
          vector<int>result;
          vector<bool>visited(V,false);
          dfsHelper(adj,0,visited,result);
          return result;
    }
};
