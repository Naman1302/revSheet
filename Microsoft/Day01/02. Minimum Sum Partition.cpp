//Recursion
class Solution{

  public:
    int solve(int a[],int n,int i,int s1,int s2,vector<vector<int>> &dp){
        if(i==n)
            return abs(s1-s2);
        if(dp[i][abs(s1-s2)]!=-1) 
            return dp[i][abs(s1-s2)];
        return dp[i][abs(s1-s2)]=min(solve(a,n,i+1,s1+a[i],s2,dp),solve(a,n,i+1,s1,s2+a[i],dp));    
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	    }
	    vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
	    return solve(arr,n,0,0,0,dp);
	} 
};
//Tabulation
class Solution{

	public:
	int solve(int arr[],int n,int sum){
	    bool dp[n+1][sum+1];
	    for(int i=0;i<=n;i++){
	        for(int j=0;j<=sum;j++){
	            if(j==0)
	                dp[i][j]=1;
	            else if(i==0)
	                dp[i][j]=0;
	            else{
	                if(arr[i-1]<=j)
	                    dp[i][j]= dp[i-1][j-arr[i-1]] || dp[i-1][j];
	                else
	                    dp[i][j]=dp[i-1][j];
	            }     
	        }
	    }
	    int m=INT_MAX;
	    for(int i=0;i<=sum;i++){
	        if(dp[n][i])
	            m=min(m,abs(sum-2*i));
	    }
	    return m;
	}
	int minDiffernce(int arr[], int n) 
	{ 
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	    }
	    return solve(arr,n,sum);
	} 
};