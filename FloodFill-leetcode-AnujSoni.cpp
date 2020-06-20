class Solution {
public:
    bool isSafe(int sr,int sc,int m,int n,vector<vector<int>>& image,int type,int newColor){
        return sr>=0 && sr<m && sc>=0 && sc<n && image[sr][sc] == type && image[sr][sc]!= newColor;
    }
    
    void dfs(vector<vector<int>>& image,int sr,int sc,int newColor,int type){
        int m = image.size();
        int n = image[0].size();
        if(image[sr][sc]==type && image[sr][sc]!=newColor)
            image[sr][sc] = newColor;
        if(isSafe(sr-1,sc,m,n,image,type,newColor))
            dfs(image,sr-1,sc,newColor,type);
        if(isSafe(sr,sc-1,m,n,image,type,newColor))
            dfs(image,sr,sc-1,newColor,type);
        if(isSafe(sr+1,sc,m,n,image,type,newColor))
            dfs(image,sr+1,sc,newColor,type);
        if(isSafe(sr,sc+1,m,n,image,type,newColor))
            dfs(image,sr,sc+1,newColor,type);
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int type = image[sr][sc];        
        dfs(image,sr,sc,newColor,type);
        return image;
    }
};
