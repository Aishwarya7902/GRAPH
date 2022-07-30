PROBLEM:                     https://leetcode.com/problems/flood-fill/
BEST VIDEO EXPLAINATION:     https://youtu.be/7aikf56h9Gs


/*approach 1
TC: same as dfs
SC: same as dfs
1.simple question
2.first attempt by urself
3.one point to be noted here is that ...we have to move to those cells only which have colour same as image[sr][sc] and we have to paint that cell with newcolor

#NOTE: EK ERROR AAYEGA ....(DEADLY SIGNAL)  LETS SEE WO KYU AAYA ...USKO SAMJHNA JARURI HAI ....FOR BETTER CLARITY SEE VIDEO NO 10 FROM GRAPH PLAYLIST BY HELLO WORLD 
CHANNEL ...START FROM  ( 15:00 MIN) 
dekho simple si bat hai .....agar initialcolor=newcolor hoga ....to wo upar niche khelta rah jayega
*/


class Solution {
public:
    bool isValid(int m,int n,vector<vector<int>>& image, int sr, int sc,int initialColor){
        if(sr>=0 && sr<m && sc>=0 && sc<n && image[sr][sc]== initialColor)
            return true;
        return false;
    }
    void dfs(int m,int n,vector<vector<int>>& image, int sr, int sc, int newcolor,int  initialColor){
       image[sr][sc]=newcolor;
        //left
        if(isValid(m,n,image,sr-1,sc,initialColor)){
            dfs(m,n,image,sr-1,sc,newcolor,initialColor);
        }
        //right
        if(isValid(m,n,image,sr+1,sc,initialColor)){
            dfs(m,n,image,sr+1,sc,newcolor,initialColor);
        }
        //up
        if(isValid(m,n,image,sr,sc-1,initialColor)){
            dfs(m,n,image,sr,sc-1,newcolor,initialColor);
        }
       //down
        if(isValid(m,n,image,sr,sc+1,initialColor)){
            dfs(m,n,image,sr,sc+1,newcolor,initialColor);
        }
       
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newcolor) {
       
        int initialColor=image[sr][sc];
        if(initialColor==newcolor)return image;
        int m=image.size();
        int n=image[0].size();
        dfs(m,n,image,sr,sc,newcolor,initialColor);
        return image;
    }
};
