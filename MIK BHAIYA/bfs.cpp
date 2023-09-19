PROBLEM:https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

class Solution {
  public:
    //helper function
    void bfsHelper(vector<int> adj[],int u,vector<bool>&visited,vector<int> &result)
    {
        queue<int>q;
        q.push(u);
        visited[u]=true;
        result.push_back(u);
        while(!q.empty())
        {
            int source=q.front();
            q.pop();
            for(int &v:adj[source]){
                if(!visited[v]){
                    q.push(v);
                    visited[v]=true;
                    result.push_back(v);
                }
            }
        }
    }
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
          vector<int> result;
          vector<bool>visited(V,false);
          bfsHelper(adj,0,visited,result);
          return result;
          
          
    }
};
