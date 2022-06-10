class Solution{
  public:
    bool canPair(vector<int> a, int k) {
        // Code here.
        if(a.size()%2!=0) return 0;
        unordered_map<int,int> mp;
        for(int i=0;i<a.size();i++){
            a[i]=a[i]%k;
            mp[a[i]]++;
        }
        for(int i=0;i<a.size();i++){
            if(a[i]!=0){
                if(a[i]==k-a[i]){
                    if(mp[a[i]]%2!=0)
                        return false;
                }
            if(mp.find(k-a[i])==mp.end())
                return false;
            if(mp[a[i]]!=mp[k-a[i]])
                return false;
            }
        }
        return true;
    }
};