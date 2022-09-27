video: (striver bhaiya...best) https://www.youtube.com/watch?v=V8qIqJxCioo&t=966s
problem: https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
 
FEEL ❤❤❤❤❤ : yar kosaraju kuch bhi ni hai bas 3 simple steps apply karna hai
1.find toposort ..toposort isliye find kar rahe coz isse wo node jisme sabse kam edges aa rahe wo stack me sabse last me aayega 
video: https://www.youtube.com/watch?v=Yh6EFazXipA&t=1s (simplest explaination by striver bhaiya)

2.transpose the graph ...reverse isliye kar rahe coz hum dusre ke component me na ghuse....dekho jo ek hi scc me honge unme edge reverse bhi kar do 
  to fark ni padega...tab bhi wo scc hi rahega...lekin agr component dusre ka hai to us case me hum edge reverse kar denge to us component me ni jayenge
  that is what we want
  
3.apply reversedfs(kuch ni bhai simple dfs hi laaga rahe bas fancy name de diya hai...darne ki koi bat ni) on the oredering we got from topo sort




class Solution
{
    private:
    void dfs(int node,stack<int>&st,vector<int>&vis,vector<int> adj[]){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,st,vis,adj);
            }
        }
        st.push(node);
    }
    
    void RevDfs(int node,vector<int>&vis,vector<int> transpose[]){
        vis[node]=1;
        for(auto it:transpose[node]){
            if(!vis[it]){
                RevDfs(it,vis,transpose);
            }
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        // step 1 -> finding an order based on dcreasing finishing time 
        vector<int>vis(V,0);
        stack<int>st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,st,vis,adj);
            }
        }
        // step 2 -> reversing the edges
        vector<int> transpose[V];
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto it: adj[i]){
                transpose[it].push_back(i);
            }
        }
        int cnt=0;
        while(!st.empty()){
          int node=st.top();
          st.pop();
          if(!vis[node]){
              cnt++;
              RevDfs(node,vis,transpose);
          }
        }
        return cnt;
    }
