/*
1.hum bat kar rahe shortest path ki ...to shortest ek refrencing word hai...to jab aap shortest path ki bat kar rahe to source ko bhi batana padega..
2.i hope source ka concept samajh aa gaya ki source ki jarurat kyu padi
3.NOW WE ARE GOING TO USE BFS ....u may ask ki why bfs ...to dekho bfs humesha pahle apne baju walon pe chalta hai(in this way
bfs humesha shortest chalta hai...so we can use this tagline very smartly to find out minimum distance ...
TO BFS KA FAYDA YE HOGA KI WO SABE SHORTEST CHALEGA

4.bahot simple hai bhai bahot simple

5.dekho humlog kya karenge ki BFS algorithm hi use karenge aur usme kuch modification karenge ki distance bhi aa jaayega
 
 
*/
VIDEO: https://youtu.be/yysA7ZM2jjA

ALGORITHM: kuch ni bhai simple bfs hai with little modification

1.initialize dist[INT_MAX,INT_MAX,INT_MAX,INT_MAX...]
2.dist[source]=0
3.initialize visited[v]={f,f,f,f,f}
4.create a queue ,q
5.q.push(source),visited[source]=true;
6.while(!q.empty())
{
  int u=q.pop();
  for(every adjacent V of u){
    if(!visited[V]){
    dist[V]=dist[u]+1;
      q.push(V);
      visited[V]=true;
    }
  }
  
}
7.print dist array
