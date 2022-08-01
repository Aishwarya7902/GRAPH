PROBLEM:     https://practice.geeksforgeeks.org/problems/topological-sort/1

/*     #initial approach
 (coded on my own after watching the intution)
 video : https://www.youtube.com/watch?v=UnzIqUy8pnI
 TC: O(V+E)
 
 PESUDO CODE FOR TOPOLOGICAL SORT
1.sabki indegree nikal lo  ( use vector)
create  a queue ,q
2.jiski bhi indegree 0 hai usko q me dal do
while(!q.empty()) {
3.ek temp variable me q ke front ko store kar lo...pop()
4.print /ans me add kar lo
5.is vertex se jitne v connected edges hai unko indegree ko reduce karo by 1 (ISKE PARENT KO GRAPH SE HATA RAHE SO INDEGREE KO 1 KAM KAR RAHE)  .....if it also comes to be 0 then push into queue
}
6.at last return ans vector

Note: if no of elements in topological sort is less than total no of vertices initially in the graph ...it means ki graph has cycle.
 
 */
class solution

{
public:
//Function to return list containing vertices in Topological order. 
vector<int> topoSort(int V, vector<int> adj[]) 
{
    // code here
    //finding indedree
    vector<int>ans;
    vector<int>indegree(V,0);
   for(int i=0;i<V;i++)
   {
        for(int u:adj[i]){
           
            indegree[u]++;
        }
    }
    queue<int>q;
    //finding vertex with 0 indegree
    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    //taking out vertex with indegree 0 and decrementing indegree of their connected vertex
    while(!q.empty()){
        int vertex=q.front();
        q.pop();
        ans.push_back(vertex);
        for(int x:adj[vertex]){
            indegree[x]--;
            if(indegree[x]==0){
                q.push(x);
            }
        }
    }
   return ans; 
}
};

/*APPROACH 2 :USING STACK
VIDEO:  https://youtu.be/tv8yJLKOZ0g
*/

//DFS IMPLEMENTATION

class solution

{

public:
//Function to return list containing vertices in Topological order.
void DFS(vector<int> adj[],vector<bool>&visited,int s,stack<int>&st){
    visited[s]=true;
    for(int v:adj[s]){
        if(!visited[v]){
            DFS(adj,visited,v,st);
        }
    }
    st.push(s);
    
}
vector<int> topoSort(int V, vector<int> adj[]) 
{
    // code here
 stack<int>st;
 vector<bool>visited(V,false);
 for(int i=0;i<V;i++){
     if(!visited[i]){
         DFS(adj,visited,i,st);
     }
 }
 vector<int>ans;
 while(!st.empty()){
     int x=st.top();
     st.pop();
     ans.push_back(x);
 }
 return ans;
}

};

/*APPROACH 3: VECTOR ME HI PUSH KARO AND LAST ME VECTOR KO REVERSE KAR DO
VIDEO:  https://youtu.be/tv8yJLKOZ0g
*/
class solution

{
	public:
	//Function to return list containing vertices in Topological order.
	void DFS(vector<int> adj[],vector<bool>&visited,int s,vector<int>&ans){
	    visited[s]=true;
	    for(int v:adj[s]){
	        if(!visited[v]){
	            DFS(adj,visited,v,ans);
	        }
	    }
	    ans.push_back(s);
	    
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	
	 vector<bool>visited(V,false);
	 vector<int>ans;
	 for(int i=0;i<V;i++){
	     if(!visited[i]){
	         DFS(adj,visited,i,ans);
	     }
	 }
	 reverse(ans.begin(),ans.end());
	 return ans;
	}
};




