class Solution{
    public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        vector<vector<string>> ans;
        for(int len=1;len<=s.length();len++){
            string find=s.substr(0,len);
            set<string> v;
            for(int i=0;i<n;i++){
                string w=contact[i];
                if(w.substr(0,len)==find){
                    v.insert(w);
                }
            }
            if(v.size()==0){
                ans.push_back({"0"});
            }
            else{
                vector<string> t(v.begin(),v.end());
                ans.push_back(t);
            }
        }
        return ans;
        
    }
};