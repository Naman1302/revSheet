vector<string> generate(int n)
    {
    // Your code here
        vector<string> ans;
        queue<string> q;
        q.push("1");
        while(n--){
            string s=q.front();
            q.pop();
            ans.push_back(s);
            
            string t=s;
            
            s.append("0");
            t.append("1");
            
            q.push(s);
            q.push(t);
        }
        return ans;
    }