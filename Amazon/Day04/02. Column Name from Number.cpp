class Solution{
    public:
    string colName (long long int n)
    {
       n--;
       string ans="";
       while(n>=0){
           ans=string(1,n%26+'A')+ans;
           n=n/26;
           n--;
       }
       return ans;
    }
};