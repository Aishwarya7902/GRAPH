PROBLEM: https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1
VIDEO:   https://youtu.be/XhYVY6PQSxs


/*
Expected Time Complexity: O(N^2)
Expected Auxiliary Space: O(N^2)

 
*/
class Solution
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    bool isValid(int i,int j,int N,vector<vector<bool>>&visited){
        if(i>=0 && i<N && j>=0 && j<N && visited[i][j]==false)
        return true;
        return false;
    }
  
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    
	    int x=KnightPos[0]-1,y=KnightPos[1]-1;
	    int tx=TargetPos[0]-1,ty=TargetPos[1]-1;
	    if(x==tx && y==ty)return 0;
	    vector<vector<bool>>visited(N,vector<bool>(N,false));
	    queue<pair<int,int>>q;
	    q.push({x,y});
	    visited[x][y]=true;
	    int ans=0;
	    while(!q.empty()){
	       ans++;
	       int size=q.size();
	       while(size!=0){
	           pair<int,int>p=q.front();
	           q.pop();
	           int x1=p.first;
	           int y1=p.second;
	           int dx[8]={1,1,-1,-1,2,2,-2,-2};
	           int dy[8]={2,-2,2,-2,1,-1,1,-1};
	           for(int i=0;i<8;i++){
	               int nx=x1+dx[i];
	               int ny=y1+dy[i];
	               if(nx==tx && ny==ty)return ans;
	               if(isValid(nx,ny,N,visited)){
	                   visited[nx][ny]=true;
	                   q.push({nx,ny});
	               }
	           }
	           size--;
	       }
	    }
	    return ans;
	}
};

