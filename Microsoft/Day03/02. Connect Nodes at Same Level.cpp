class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
       queue<Node*> q;
       q.push(root);
       while(!q.empty()){
           Node *start=q.front();
           int s=q.size();
           for(int i=0;i<s;i++){
                Node* f=q.front();
                q.pop();
                if(i>0){
                   start->nextRight=f;
                   start=start->nextRight;
                }
                if(f->left)
                    q.push(f->left);
                if(f->right)
                    q.push(f->right);
           }
           start->nextRight=NULL;
       }
       return;
    }    
      
};