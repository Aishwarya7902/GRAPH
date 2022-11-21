PROBLEM:  https://practice.geeksforgeeks.org/problems/number-of-provinces/1
VIDEO :(STRIVER BHAIYA) https://youtu.be/ZGr5nX-Gi6Y

/*
tc: O(v^2)
sc: for storing size ,parent array
*/
class DisjointSet{
    
    public:
    vector<int>size,parent;
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
    
class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        DisjointSet ds(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                
                if(adj[i][j]==1){
                   
                    ds.FindUnionBySize(i,j);
                    
                }
            }
        }
        /*for no of provinces ...we have to simply return no of connected
        components .....thia can be done by two methods
        METHOD 1:
        and for that we can find the no of ultimate parents
        or the bosses....now for that...if a no is the ultimate parent of
        himself then it is  a  boss
        
        METHOD 2:
        if  if(ds.parent[i]==i) then also i is the boss
        */
        int cnt=0;
        for(int i=0;i<V;i++){
          //  if(ds.FindUParent(i)==i)cnt++;
           if(ds.parent[i]==i)cnt++;
        }
       return cnt; 
    }
