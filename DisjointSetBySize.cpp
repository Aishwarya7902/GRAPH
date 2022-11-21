video: (striver bhaiya) https://www.youtube.com/watch?v=aBxjDBC4M1U&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=46
//tc :o(4alpha) which is nearly about constant (it has a huge mathematical derivation...and interviewer is not gonna ask u...he will only focus on ur logic
#include <bits/stdc++.h>
using namespace std;
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
    
