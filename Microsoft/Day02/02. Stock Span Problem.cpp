//#NGL
class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int p[], int n)
    {
       // Your code here
       stack<pair<int,int>> s;
       vector<int> ans;
       for(int i=0;i<n;i++){
          if(s.empty()){
              ans.push_back(-1);
          } 
          else if(!s.empty() && s.top().first>p[i]){
              ans.push_back(s.top().second);
          }
          else if(!s.empty() && s.top().first<=p[i]){
              while(!s.empty()){
                  if(s.top().first>p[i]){
                      break;
                  }
                  else{
                      s.pop();
                  }
                }  
                if(s.empty()){
                      ans.push_back(-1);
                }
                else{
                    ans.push_back(s.top().second);
                }
          }
          s.push({p[i],i});
       }
       for(int i=0;i<n;i++){
           ans[i]=i-ans[i];
       }
       return ans;
    }
};
