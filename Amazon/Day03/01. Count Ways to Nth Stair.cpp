class Solution{
    public:
        long long solve(int m,vector<long long> &dp){
            if(m<=0)
                return 0;
            if(m==1||m==2)
                return m;
            if(dp[m]!=-1)
                return dp[m];
            long long oneback=solve(m-1,dp);
            long long twoback=solve(m-2,dp);
            return dp[m]=min(oneback,twoback)+1;
        }
        long long countWays(int m)
        {
            vector<long long> dp(m+1,-1);
            return solve(m,dp);
        }
};