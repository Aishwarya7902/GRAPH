PROBLEM:https://practice.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bipartite-graph
VIDEO:https://www.youtube.com/watch?v=-vu34sct1g8


/*
TC:O(V+E) //SAME AS BFS
SC:O(V+E) //SAME AS BFS
*/

class Solution {
private:
bool bfs(int source,int V, vector<int>adj[],int color[]){
   queue<int>q;
   color[source]=0;
   q.push(source);
   while(!q.empty()){
       int node=q.front();
       q.pop();
       for(auto it:adj[node]){
           //if yet not coloured...color it with opposite of node
           if(color[it]==-1){
               color[it]=!color[node];
               q.push(it);
           }
           else if(color[it]==color[node])return false;
       }
   }
   return true;
}
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    int color[V];
	    //initialisation
	    for(int i=0;i<V;i++){
	       color[i]=-1; 
	    }
	    //calling each component
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            if(bfs(i,V,adj,color)==false)
	             return false;
	        }
	    }
	    return true;
	}

};
