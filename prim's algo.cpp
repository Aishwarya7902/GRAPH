/* THIS ALGORITHM IS USED TO FIND MINIMUM SPANNING TREE OF A GIVEN GRAPH*/

/* brute force:
tc: greater than O(n^2)
sc: size of adjacency lists used
video:https://www.youtube.com/watch?v=oNTsS8lGDHw&t=265s


*/
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	//no need of parent here still we did coz striver bhaiya ne kiya tha 
  //refer this comment of (prim's version ) vibhavco20b741 for clarity


  
 
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int parent[V];
        int key[V];
        bool mst[V];
        int ans=0;
        for(int i=0;i<V;i++){
            parent[i]=-1;
            key[i]=INT_MAX;
            mst[i]=false;
        }
        parent[0]=-1;
        key[0]=0;
        for(int count=0;count<V;count++){
            int mini=INT_MAX,u;
            for(int i=0;i<V;i++){
                if(mst[i]==false && key[i]<mini)
                mini=key[i],u=i;
            }
            ans+=mini;
            mst[u]=true;
            for(int i=0;i<adj[u].size();i++){
                
                int x=adj[u][i][0];
                int wt=adj[u][i][1];
                if(mst[x]==false && wt<key[x])
                key[x]=wt,parent[x]=u;
            }
            
        }
        
      return ans;  
    }
};
