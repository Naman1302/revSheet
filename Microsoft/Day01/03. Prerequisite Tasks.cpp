lass Solution {
public:
	bool isPossible(int n, vector<pair<int, int> >& prereq) {
	    vector<int> adj[n];
	    vector<int> indegree(n,0);
	    for(int i=0;i<prereq.size();i++){
	        adj[prereq[i].second].push_back(prereq[i].first);
	        indegree[prereq[i].first]++;
	    }
	    queue<int> q;
	    for(int i=0;i<n;i++){
	        if(indegree[i]==0)
	            q.push(i);
	    }
	    int count=0;
	    while(!q.empty()){
	        int f=q.front();
	        q.pop();
	        count++;
	        for(auto x:adj[f]){
	            indegree[x]--;
	            if(indegree[x]==0)
	                q.push(x);
	        }
	    }
	    return count<n?false:true;
	}
};