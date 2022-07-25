class Solution {
  public:
    int solve(int a[],int n,int k,int c,int i,bool buy,vector<vector<vector<int>>> &dp){
        //base case
        if(i>=n|| c>=k)
            return 0;
        //========

        if(dp[i][c][buy]!=-1)
            return dp[i][c][buy];
            
        //if buy =1 means we have to buy now
        //else we have to sell now
        
        if(buy){ //now we can either buy a[i] or we can skip it and try next to buy
            return dp[i][c][buy]=max(-a[i]+solve(a,n,k,c,i+1,!buy,dp),solve(a,n,k,c,i+1,buy,dp));
        }    
        else{ //now we can either sell prices[i] or we can skip it and try next to sell
            return dp[i][c][buy]=max(a[i]+solve(a,n,k,c+1,i+1,!buy,dp),solve(a,n,k,c,i+1,buy,dp));
        }
    }
    int maxProfit(int k, int n, int a[]) {
        if(n<2*k){
            int sum=0;
            for(int i=1;i<n;i++){
                sum+=max(0,a[i]-a[i-1]);
            }
            return sum;
        }
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(k,vector<int>(2,-1)));
        return solve(a,n,k,0,0,true,dp);
    }
};