class Solution{
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > mat, int row, int col) 
    {
        int t=0,b=row-1,l=0,r=col-1;
        vector<int> ans;
        while(l<=r && t<=b){
            for(int i=l;i<=r;i++){
                ans.push_back(mat[t][i]);
            }
            t++;
            for(int i=t;i<=b;i++){
                ans.push_back(mat[i][r]);
            }
            r--;
            if(t<=b){
                for(int i=r;i>=l;i--){
                    ans.push_back(mat[b][i]);
                }
                b--;
            }
            if(l<=r){
                for(int i=b;i>=t;i--){
                    ans.push_back(mat[i][l]);
                }
                l++;
            }
        }
        return ans;
    }
};