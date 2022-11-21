PROBLEM:https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
VIDEO: (STRIVER BHAIYA)  https://youtu.be/DMnDM_sxVig

class DisjointSet{
    vector<int>size,parent;
    public:
    DisjointSet(int n){
        size.resize(n+1,0);
        parent.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
          size[i]=1;
        }
    }
  
  //parent find
    int FindUParent(int node){
        if(node==parent[node])return node ;
      return  parent[node]=FindUParent(parent[node]);
    }
  
  //union
    
    void FindUnionBySize(int u,int v){
        int ulP_u=FindUParent(u);
        int ulP_v=FindUParent(v);
        if(ulP_v==ulP_u)return;
        if(size[ulP_v]<size[ulP_u]){
            parent[ulP_v]=ulP_u;
            size[ulP_u]+=size[ulP_v];
        }
       
        else{
            parent[ulP_u]=ulP_v;
            size[ulP_v]+=size[ulP_u];
        }
    }
};
class Solution{
  {   
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        //SPACE COMPEXITY IS: O(M)+ space for parent and size array in dsu
        vector<pair<int,pair<int,int>>> edges;
        //O(N+E)
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int node=i;
                int adjNode=it[0];
                int wt=it[1];
                edges.push_back({wt,{node,adjNode}});
            }
        }
        //O(MlogM) for sorting
        sort(edges.begin(),edges.end());
        /*SINCE WE ARE MOVING ACROSS ALL EDGES AND FOR EACH EDGE WE ARE DOING DSU..
        HENCE TIME COMPEXITY WILL BE : O(M*4*alpha*2)
        we did *2 because to find ultimate parent takes 4alpha and we did dsu
        which also takes 4*alpha....hence we did twice
        */
        
        DisjointSet ds(V);
        int mstwt=0;
        for(auto it:edges){
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            if(ds.FindUParent(u)!=ds.FindUParent(v)){
                mstwt+=wt;
                ds.FindUnionBySize(u,v);
            }
            
        }
       return mstwt; 
    }
};
