class Solution{
public:
	    int mod=1e9+7;
		int CountWays(string str){
		    // Code here
		    int n=str.length();
		    if(str[0]=='0') return 0;
		    vector<int> count(n+1,0);
		    count[0]=count[1]=1;
		    for(int i=2;i<=n;i++){
		        if(str[i-1]>'0'){
		            count[i]=count[i-1]%mod;
		        }
		        if(str[i-2]=='1'||(str[i-2]=='2'&& str[i-1]<'7')){
		            count[i]=(count[i]+count[i-2])%mod;
		        }
		    }
		    return count[n];
		}

};