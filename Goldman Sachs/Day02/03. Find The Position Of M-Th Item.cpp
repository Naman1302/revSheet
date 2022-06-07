class Solution {
  public:
    int findPosition(int N , int M , int K) {
        // code here
        return (K+M-2)%(N)+1;
    }
};