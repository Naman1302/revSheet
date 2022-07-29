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
class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        if(!root) 
            return 0;
            
        unordered_map<Node*,Node*> mp;
        
        queue<Node*> q;
        q.push(root);
        
        Node* t;
        
        while(!q.empty()){
            Node* f=q.front();
            q.pop();
            if(f->data==target){
                t=f;
            }
            if(f->left){
                q.push(f->left);
                mp[f->left]=f;
            }
            if(f->right){
                q.push(f->right);
                mp[f->right]=f;
            }
        }
        q.push(t);
        int timer=0;
        unordered_map<Node*,bool> vis;
        while(!q.empty()){
            int s=q.size();
            bool burn=false;
            while(s--){
                Node* f=q.front();
                q.pop();
                if(mp.find(f)!=mp.end() && !vis[mp[f]]){
                    q.push(mp[f]);
                    burn=true;
                }
                if(f->left && !vis[f->left]){
                    q.push(f->left);
                    burn=true;
                }
                if(f->right && !vis[f->right]){
                    q.push(f->right);
                    burn=true;
                }
                vis[f]=true;
            }
            if(burn){
                timer++;
            }
        }
        return timer;
    }
};