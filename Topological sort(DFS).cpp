PROBLEM:     https://practice.geeksforgeeks.org/problems/topological-sort/1
/*APPROACH 1 :USING STACK
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

/*APPROACH 2: VECTOR ME HI PUSH KARO AND LAST ME VECTOR KO REVERSE KAR DO
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




