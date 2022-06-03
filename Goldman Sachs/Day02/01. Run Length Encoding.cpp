string encode(string src)
{     
  //Your code here 
  src.push_back('*');
  string ans;
  int count=1;
  char c=src[0];
  for(int i=1;i<src.length();i++){
      if(src[i]!=c){
          ans+=c;
          c=src[i];
          string add=to_string(count);
          ans+=add;
          count=1;
      }
      else
        count++;
  }
  
  return ans;
} 