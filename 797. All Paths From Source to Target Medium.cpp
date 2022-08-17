/*
PROBLEM:https://leetcode.com/problems/all-paths-from-source-to-target/
VIDEO:https://youtu.be/X6b02KyeyLU
TC: same as dfs i.e O(V+E)
SC: O(N)
*/

class Solution {
public:
    void dfs(vector<vector<int>>& graph,int s,vector<vector<int>>&ans,vector<int>&path){
        
        
        path.push_back(s);
        if(s==graph.size()-1)
            ans.push_back(path);
        else{
        for(auto u:graph[s]){
            
                dfs(graph,u,ans,path);
            
        }
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>ans;
     
        vector<int>path;
     
          dfs(graph,0,ans,path);   
    return ans;
     }
       
   
};
