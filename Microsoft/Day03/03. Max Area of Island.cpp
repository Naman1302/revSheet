class Solution{
    public:
    int dfs(vector<vector<int>> &g,int i,int j,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m || g[i][j]==0){
            return 0;
        }
        int ans=0;
        g[i][j]=0;
        
        ans+=dfs(g,i+1,j+1,n,m);
        ans+=dfs(g,i,j+1,n,m);
        ans+=dfs(g,i-1,j+1,n,m);
        ans+=dfs(g,i-1,j,n,m);
        ans+=dfs(g,i-1,j-1,n,m);
        ans+=dfs(g,i,j-1,n,m);
        ans+=dfs(g,i+1,j-1,n,m);
        ans+=dfs(g,i+1,j,n,m);
        
        return 1+ans;
    }
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& g) {
        int area=INT_MIN;
        int n=g.size(),m=g[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==1){
                    area=max(area,dfs(g,i,j,n,m));
                }
            }
        }
        return area;
    }
};