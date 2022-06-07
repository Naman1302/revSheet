class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int count=0,j=0;
        long long prod=1;
        for(int i=0;i<n;i++){
            prod=prod*a[i];
            while(j<n&&prod>=k){
                prod=prod/a[j];
                j++;
            }
            if(prod<k)
            count+=i-j+1;
        }
        return count;
    }
};