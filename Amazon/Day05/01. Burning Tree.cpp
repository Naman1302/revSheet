class Solution {
  public:
    int ans=0;
    void dfs(Node *root,int t){
        ans=max(ans,t);
        if(!root)
            return;
        dfs(root->left,1+t);
        dfs(root->right,1+t);
    }
    int dfs1(Node *root,int target){
        if(!root)
            return 0;
        if(root->data==target){
            dfs(root->left,0);
            dfs(root->right,0);
            return 1;
        }
        int l = dfs1(root->left,target);
        int r = dfs1(root->right,target);
        if(l){
            dfs(root->right,l);
            return 1+l;
        }
        if(r){
            dfs(root->left,r);
            return 1+r;
        }
        return 0;
    }
    int minTime(Node* root, int target) 
    {
        dfs1(root,target);
        return ans;
    }
};
// BFS Approach
