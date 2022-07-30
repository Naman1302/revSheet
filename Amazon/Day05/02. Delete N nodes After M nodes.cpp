class Solution
{
    public:
    void linkdelete(struct Node  *head, int m, int n)
    {
        Node* curr=head;
        while(curr!=NULL){
            int skip=m;
            while(curr!=NULL && skip>1){
                skip--;
                curr=curr->next;
            }
            if(!curr)
                break;
            Node *temp=curr->next;
            int del=n;
            while(temp!=NULL && del!=0){
                del--;
                temp=temp->next;
            }
            curr->next=temp;
            curr=temp;
        }
        return;
    