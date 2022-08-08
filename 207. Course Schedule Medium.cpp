/*
PROBLEM:  https://leetcode.com/problems/course-schedule/
VIDEO:    https://youtu.be/rybxMwv1fw8
TC:  same as dfs i.e O(V+E)
SC:  same as dfs i.e O(V+E)

short notes:
1.question says ki in order to [ai,bi] take course ai u must first take course bi
ANALYSIS:
1.hey dont u think that it is a kind of topological sort...for each edge uv in graph u-->v in order to visit v you must first visit  u.
2.hence This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists,
no topological ordering exists and therefore it will be impossible to take all courses.
3.lets see how to break down a bigger problem into a smaller one
 course schedule
       |
       |
       |
      \-/
 if we can make topological sort or not
      |
       |
       |
      \-/
 isCylic
 agr cyclic hai it means topological sort(coz only DAG ...directed acyclic graph is allowed)  ni kar sakte hence course ko scheule bhi ni kar sakte hence return false
 
 */

class Solution {
public:
    bool dfs(int s,vector<int>adj[],vector<bool>&visited,vector<bool>&dfsvisited){
        visited[s]=true;
        dfsvisited[s]=true;
        for(int u:adj[s]){
            if(!visited[u]){
               if(dfs(u,adj,visited,dfsvisited))return true;
            }
            else if(dfsvisited[u])return true;
        }
        
        dfsvisited[s]=false;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& pre) {
        
       vector<bool>visited(n,false),dfsvisited(n,false);
        vector<int>adj[n];
        //learnt how to make adjacency list in this question
        for(int i=0;i<pre.size();i++){
          int u=pre[i][0];
            int v=pre[i][1];
            adj[v].push_back(u);
        }
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(dfs(i,adj,visited,dfsvisited))return false;
            }
        }
        return true;
    }
};


