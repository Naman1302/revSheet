// I  D  D  I  D  D
// |        |      -> breakpoints
//1 '4 3 2 <-' '7 6 5 <-'
// jab bhi decreasing toh stack mein bharte jaao  kyunki we need to increase 
// sufficently minimum in last added so thatit satisfies the decreasing cond'n  
// O(N) + O(N)

string printMinNumberForPattern(string S){
       // code here 
       stack<int>stk;
       int num=1;
       string res="";
       for(int i=0;i<S.length();i++){
           if(S[i]=='D'){
               stk.push(num);
               num++;
           }
           else{
               stk.push(num);
               num++;
               while(!stk.empty()){
                   res+=to_string(stk.top());
                   stk.pop();
               }
           }
       }
       stk.push(num);
       while(!stk.empty()){
           res+=to_string(stk.top());
                   stk.pop();
       }
       return res;
       
   }

//==========================

// O(N) + O(1)

class Solution{
public:
    string printMinNumberForPattern(string s){
        // code here
        int n=s.length();
        int i=0,j=0;//i stores postion and j stores last greatest number added to string
        int cnt=1; 
        string ans="";//stores sequence
        while(i<=n){
            if(s[i]=='I'||i==s.size()){//if increasing => a breakpoint and end is also a breakpoint
                while(cnt>=1){
                    if(cnt<=j) break;//last greatest se bade number hi daalneh cause no rep allowed
                    ans+=to_string(cnt);
                    cnt--;
                }
                j=i+1;//last ko update kar diya
                cnt=i+1;//count ko update kardiya 
            }
            cnt++;//ab vlue badhayi jaaye increasing ki ramyan khatam hone ke baad
            i++;//pointer ++
        }
        return ans;
    }
};