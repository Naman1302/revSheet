int ans;
int solve(Node* root,int s){
    if(!root)
        return 0;
    int l=solve(root->left,s);
    int r=solve(root->right,s);
    
    
    if((l+r+root->data)==s)
        ans++;
        
    return l+r+root->data;
    
}
int countSubtreesWithSumX(Node* root, int X)
{
	ans=0;
	solve(root,X);
	return ans;
}