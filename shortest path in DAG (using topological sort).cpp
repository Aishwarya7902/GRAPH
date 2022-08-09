VIDEO : https://youtu.be/-Oe4PWZ6G6k
/*
1. DAG means directed acyclic graph
2.weight diya hai basically hume shortest path nikalana hai
3. IN THIS HUMLOG DEKHENGE KI TOPOLOGICAL SORT SE SHORTEST PATH IN DAG KAISE NIKALTE HAIN
4.to dekhte hain ki ye algo run kaise kar raha topological sort ke according
topological sort hum kyu kiyen ...becoz humlog pahle wo cheez khtam karna chah rahe jispe dependency sabse kam hai
(vae mere ...it means wahan tum free me pahunch rahe).....fir thode jyada dependency pe jayenge ....fir usse jyada ...and so on and so forth..
YE BAHOT ACHA CONCEPT HAI ..BILKUL HALKE ME MAT LENA ISKO😐
*/

ALGORITHM (A LOVE ALGO ❤❤)
1. dist[v]={INT_MAX,INT_MAX,INT_MAX...}
2.dist[source]=0
3.find topological sort of graph
4.for every vertex u in topological sort
 {
     for(every adjacent v of u){
     if(dist[v]>dist[u]+weight(u,v))
     {
     dist[v]=dist[u]+weight(u,v);
     }
     }
 }
