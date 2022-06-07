class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& sl) {
        //code here
        vector<vector<string>> ans;
        unordered_map<string,vector<int>> mp;
        for(int i=0;i<sl.size();i++){
            string t=sl[i];
            sort(t.begin(),t.end());
            mp[t].push_back(i);
        }
        for(auto word:mp){
            vector<string> temp;
            vector<int> ana=word.second;
            for(int i=0;i<ana.size();i++){
                temp.push_back(sl[ana[i]]);
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};