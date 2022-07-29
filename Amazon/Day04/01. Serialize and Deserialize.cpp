class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    void s(Node * root, vector<int>&v){
        if (!root) return;
        s(root->left,v);
        v.push_back(root->data);
        s(root->right,v);
    }

    vector<int> serialize(Node *root) {
        vector<int>v;
        s(root,v);
        return v;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       Node * head = new Node(A[0]);
       Node * temp = head;
       int x = A.size()-1;
       int l = 1;
       while(x--){
           Node * n = new Node(A[l]);
           temp->right = n;
           temp = temp->right;
           l++;
       }
       return head;
    }

};