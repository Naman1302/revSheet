//#queue and #hash wala
class Solution{
    public :
    string FirstNonRepeating(string A){
		    int a[26] ={0};
		    queue<char> q;
		    string ans="";
		    for(int i=0;i<A.length();i++){
		        a[A[i]-'a']++;
		        if(a[A[i]-'a']==1)
		            q.push(A[i]);
		        while(!q.empty() && a[q.front()-'a']!=1){
		             q.pop();
		        }
		        if(q.empty())
		            ans+="#";
		        else
		            ans+=q.front();
		    }
		    return ans;
		}
};

//#DLL Wala
class Node{
public:
    char data;
    Node* next = NULL;
    Node* prev = NULL;

    Node(){
        //basic constructor
    }
    Node(char data){
        this -> data = data;
    }
};
//add a node
void append(Node** head,Node** tail,char data){
    Node* newnode = new Node(data);
    if(*head == NULL){
        *head = *tail = newnode;   
        return;
    }
    (*tail) -> next = newnode;
    newnode -> prev = *tail;
    *tail = newnode;
}
//remove a node
void removeNode(Node** head, Node** tail, Node* temp){
    
    if(!*head){
        return;
    }
    //if at start
    if(*head == temp){
        *head = (*head) -> next;
    }
    //if at end
    if(*tail == temp){
        *tail = (*tail) -> prev;
    }
    //in between
    if(temp->next != NULL){
        temp -> next -> prev = temp -> prev;
    }
    if(temp -> prev != NULL){
        temp -> prev -> next = temp -> next;
    }
    //===========
    free(temp);//remove from memory
}


void firstNonRepeating(string S, string& B){
    B = "";
    Node* inDLL[256] = {NULL};//check if this node is in DLL
    bool rpted[256] = {false};//check if it's been repeated
        
    for(int i=0;i<256;i++){
        inDLL[i] = NULL;
        rpted[i] = false;
    }

    Node* head = NULL,* tail = NULL;
    
    for(int i = 0;i < S.length(); i++){
        char ch = S[i];
        //if not repeated then
        if(!rpted[ch]){
            //if it is been included or not
            if(inDLL[ch] == NULL){
                append(&head,&tail,S[i]);
                inDLL[ch] = tail;
            }
            else{
                //remove the repeeating from the list and set it as repeated
                removeNode(&head,&tail,inDLL[ch]);
                inDLL[ch] = NULL;
                rpted[ch] = true;
            }
        }
        //if !q.empty()
        if(head != NULL){
            B += head -> data;
        }
        else{
            B += '#';
        }
        return;
    }
}
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    if(A.length() <= 1){
                return A;
            }
            string ans;
            firstNonRepeating(A,ans);
            return ans;
		}
};