/*
A simple and efficient approach O(E) time complexity

Start from ‘c’ and visit all the vertices reachable from ‘c’, 
the only thing to keep in mind is to not go to ‘d’ directly from ‘c’.
Finally, if ‘d’ was reachable from ‘c' without going directly to ‘d’ from ‘c’ 
then c-d is not a bridge.

*/
class Solution{
    public:
    //Function to find if the given edge is a bridge in graph.
    void dfs(vector<int> adj[],vector<bool> & vis,int c,int d,int curr){
        vis[curr]=true;
        for(auto i:adj[curr]){
            if((curr == c && i == d) || vis[i])
                continue;
            dfs(adj, vis, c, d, i);
        }
    }
    int isBridge(int v, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<bool> vis(v,false);
        dfs(adj,vis,c,d,c);
        
        return !vis[d];
    }
};
