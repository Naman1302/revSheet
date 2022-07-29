class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
       vector<int> ans;
       deque<int> q;
       int j=0;
       for(int i=0;i<n;i++){
           while(!q.empty() && q.back()<arr[i]){
               q.pop_back();
           }
           q.push_back(arr[i]);
           if(i-j+1==k){
               ans.push_back(q.front());
               if(arr[j]==q.front()){
                   q.pop_front();
               }
               j++;
           }
       }
       return ans;
    }
};