PROBLEM:    https://leetcode.com/problems/find-the-town-judge/
VIDEO:      https://youtu.be/V_MPL5O-hDw
/*APPROACH 1
TC:
SC:
*/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
    unordered_map<int,vector<int>>trustsWhom;
    unordered_map<int,vector<int>>trustedBy;
      for(int i=0;i<trust.size();i++){
          int u=trust[i][0];
          int v=trust[i][1];
          trustsWhom[u].push_back(v);
          trustedBy[v].push_back(u);
         
          
      }
        for(int i=1;i<=n;i++){
            if(trustsWhom.find(i)==trustsWhom.end() && trustedBy[i].size()==n-1)return i;
        }
        return -1;
    }
};

/*APPROACH 2
TC:
SC:
*/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
    unordered_map<int,int>mp;
    
      for(int i=0;i<trust.size();i++){
          int u=trust[i][0];
          int v=trust[i][1];
          //jab kisi pe trust karega to minus karo
          //jab koi uspe trust karega to plus
          //coz we want ki (indegree-outdegree)==n-1 hona chahiye
          mp[u]--;
          mp[v]++;
          
         
          
      }
        for(int i=1;i<=n;i++){
            if(mp[i]==n-1)return i;
        }
        return -1;
    }
};
