/*PROBLEM:https://leetcode.com/problems/find-eventual-safe-states/
VIDEO:https://youtu.be/4ymVOCiQBtw
TC: SAME AS DFS .ie O(V+E)
SC:SAME AS DFS  .ie O(V+E)  
*/



//idea is simple ...those vertex which are not a part of cycle will be safe nodes
class Solution {
public:
    bool dfs(int s,vector<vector<int>>&graph,vector<bool>&visited,vector<bool>&dfsVisited,vector<bool>&present){
        
        visited[s]=true;
        dfsVisited[s]=true;
        for(auto u:graph[s]){
            if(!visited[u]){
                if(dfs(u,graph,visited,dfsVisited,present)){
                    return present[s]=true;
                }
            }
            else if(dfsVisited[u]){
                return present[s]=true;
            }
        }
        dfsVisited[s]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>ans;
        int n=graph.size();
        vector<bool>visited(n,false),dfsVisited(n,false);
        vector<bool>present(n);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,graph,visited,dfsVisited,present);
            }
        }
        for(int i=0;i<n;i++){
            if(!present[i])ans.push_back(i);
        }
        return ans;
    }
};
