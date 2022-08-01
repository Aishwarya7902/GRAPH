PROBLEM:  https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
VIDEO:    https://youtu.be/TL9oORCqHe8

/*MY APPROACH
Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)



PSEUDO CODE:
1.dekh vae simple si bat hai ...humlog  "Kahn's Algorithm"  ko use karenge....agr kahn's algorithm ke topological sort karne pe uska size agr no of vertex in 
graph aa gaya it means koi cycle ni .....because we can apply topological sort only in DIRECTED ACYCLIC GRAPH.

2.agr equal ni aaya it means kahin na kahin cycle hai graph me...hence return true.
*/

Kahn's Algorithm(USING BFS)

class Solution

{

public:
   // Function to detect cycle in a directed graph.
   bool isCyclic(int V, vector<int> adj[]) {
       // code here
       vector<int>indegree(V,0);
       for(int i=0;i<V;i++){
           for(int u:adj[i]){
               indegree[u]++;
           }
       }
       queue<int>q;
       for(int i=0;i<V;i++){
           if(!indegree[i]){
               q.push(i);
           }
       }
       int cnt=0;
       while(!q.empty()){
           int vertex=q.front();
           q.pop();
           cnt++;
           for(int u:adj[vertex]){
               indegree[u]--;
               if(!indegree[u])q.push(u);
           }
       }
       if(cnt==V)return false;
       else return true;
       
   }
};






