
/*
Simple window sliding doesn't work. You should think of some data structure to act as window of size 
k with some feature of getting max of k elements in O(1) time.

We Use Deque 
*/

class Solution{
      public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        int i=0;
        vector<int> ans;
        deque<int> q;
        for(int j=0;j<n;j++){
         
        //remove the elements smaller than arr[j] as they //can never be max 
            while(q.size() && q.back()<arr[j])       
                q.pop_back();
             
            //push element in the deque 
            q.push_back(arr[j]);
            if(j-i+1==k){
                 //ans will always be in front as smaller //than that in front has been already popped
                ans.push_back(q.front());
                 
                 //to move the window remove arr[i] if it //is front.
                if(arr[i]==q.front())  
                    q.pop_front();
                i++;
                
            }
        }
    return ans;
    }
};
/*

example : 3 1 0 -1 5 5 2 -1 0    let k=3;

d=deque

d=  3

d= 3, 1 (1 may be ans in next window )

d= 3,1,0 (the same way 0 can be ans)  max=q.front() =3 remove arr[i]=3 

d=1,0,-1  (the same way -1)   max=q.front()=1 remove arr[i]=1

d=0,-1, before pushing 5 remove smaller than it as they can never be ans for next windows ,
d=5  max=q.front()=5

d=5,5  max .q,front() =5

d= 5,5,2  (2 can be ans for next windows)  max=5 remove 5 d=5,2

d= 5,2,-1  (-1 can be ans) max =5;  remove 5 d=2,-1;

d=2,-1 (before pushing 0 remove smaller than 0) d=2,0 max =2

ans = 3,1,5,5,5,5,2

*/