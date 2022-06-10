class Solution {
public:
    int minSubArrayLen(int t, vector<int>& a) {
        int n=a.size();
        int l=n+1;
        int sum=0;
        
        int f=0,b=0;
    
        while(f<n){
            sum+=a[f];
            while(sum>=t){
                l=min(l,f-b+1);
                sum-=a[b];
                b++;
            }
            f++;
        }
        return l==n+1?0:l;
    }
};