class Solution
{
    public:
   vector<string> ans;
   vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
       
   void solve(int idx, int a[], int n, string& str){
       if(idx == n){
           ans.push_back(str);
           return;
       }
       
       for(int i=0;i<keypad[a[idx]].size();i++){
           str.push_back(keypad[a[idx]][i]);
           solve(idx+1, a, n, str);
           str.pop_back();
       }
   }
   vector<string> possibleWords(int a[], int N)
   {
       //Your code
       string str = "";
       solve(0, a, N, str);
       return ans;
   }
};