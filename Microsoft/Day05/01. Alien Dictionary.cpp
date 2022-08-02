class Solution{
    public:
    string findOrder(string dict[], int n, int k) {
        //code here
        vector<int> o[k];
        for(int i=1;i<n;i++){
            string a=dict[i-1];
            string b=dict[i];
            int j=0;
            for(j=0;j<min(a.length(),b.length());j++){
                if(a[j]!=b[j]){
                    o[a[j]-'a'].push_back(b[j]-'a');
                    break;
                }
            }
        }
        vector<int> indegree(k,0);
        queue<int> q;
        for(auto x:o){
            for(auto y:x){
                indegree[y]++;
            }
        }
        for(int i=0;i<k;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        string ans="";
        while(!q.empty()){
            int f=q.front();
            ans+=(f+'a');
            q.pop();
            for(auto x:o[f]){
                indegree[x]--;
                if(indegree[x]==0)
                    q.push(x);
            }
        }
        return ans;
    }
};