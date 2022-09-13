FEEL ❤❤💕💕💕💕 : MINIMUM DISTACE WALE KO SABSE PAHLE UTHAO AND DEKHTE CHALE JAO KI KYA TUM KUCH BETTER CONTRIBUTION KAR SAKTE HO.....IF HAN THEN PROIRITY QUEUE ME DAL 
DO AND REPEAT THIS UNTILL THE PQ IS EMPTY

VIDEO: https://www.youtube.com/watch?v=jbhuqIASjoM&t=491s

TC: O((N+E)logN)
            /\ this is for priority queue
    
SC: O(N ) distance array + O(N) priority queue
for better understanding of tc and sc visit : https://youtu.be/jbhuqIASjoM?t=943

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,source;
            cin>>n>>m;
	vector<pair<int,int> > g[n+1]; 	// assuming 1 based indexing of graph
	// Constructing the graph
            int a,b,wt;
	for(int i=0;i<m;i++){
               cin>>a>>b>>wt;
               g[a].push_back(make_pair(b,wt));
               g[b].push_back(make_pair(a,wt));
            }
            cin>>source;
	// Dijkstra's algorithm begins from here
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>>> pq;
	vector<int> distTo(n+1,INT_MAX);//1-indexed array for calculating shortest paths
	distTo[source] = 0;
	pq.push(make_pair(0,source));	// (dist,source)
	while( !pq.empty() ){
		int dist = pq.top().first;
		int prev = pq.top().second;
		pq.pop();
		vector<pair<int,int> >::iterator it;
		for( it = g[prev].begin() ; it != g[prev].end() ; it++){
			int next = it->first;
			int nextDist = it->second;
			if( distTo[next] > distTo[prev] + nextDist){
				distTo[next] = distTo[prev] + nextDist;
				pq.push(make_pair(distTo[next], next));
			}
		}
	}
	cout << "The distances from source " << source << " are : \n";
	for(int i = 1 ; i<=n ; i++)	cout << distTo[i] << " ";
	cout << "\n";
	return 0;
}




