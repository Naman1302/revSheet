class Solution{
public:	

	void matchPairs(char nuts[], char bolts[], int n) {
	    // code here
	    map<char,int> m;
	    m.insert({'!',1});
	    m.insert({'#',1});
	    m.insert({'$',1});
	    m.insert({'%',1});
	    m.insert({'&',1});
	    m.insert({'*',1});
	    m.insert({'@',1});
	    m.insert({'^',1});
	    m.insert({'~',1});
	    for(int i=0;i<n;i++){
	        m[nuts[i]]++;
	    }
	    int j=0;
	    for(auto y:m){
	        if(y.second==2){
	            bolts[j]=nuts[j]=y.first;
	            j++;
	        }
	    }
	    return;
	}

};