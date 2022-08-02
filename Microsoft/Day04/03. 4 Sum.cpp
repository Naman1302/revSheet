class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        set<vector<int>> s;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int sum=arr[i]+arr[j];
                int l=j+1,h=n-1;
                while(l<h){
                    int rem=arr[l]+arr[h];
                    if(rem+sum>k)
                        h--;
                    else if(rem+sum<k)
                        l++;
                    else{
                        s.insert({arr[i],arr[j],arr[l],arr[h]});
                        l++;
                        h--;
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for(auto v:s)
            ans.push_back(v);
        return ans;
    }
};