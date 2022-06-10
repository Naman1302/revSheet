class Solution{
public:
    //Function to return the sorted array.
    vector<int> nearlySorted(int a[], int n, int k){
        vector<int> ans;
        priority_queue<int,vector<int>,greater<int>> minh;
        for(int i=0;i<=k;i++){
            minh.push(a[i]);
        }
        ans.push_back(minh.top());
        minh.pop();
        for(int i=k+1;i<n;i++){
            minh.push(a[i]);
            ans.push_back(minh.top());
            minh.pop();
        }
        while(!minh.empty()){
            ans.push_back(minh.top());
            minh.pop();
        }
        return ans;
    }
};