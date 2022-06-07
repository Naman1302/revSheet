class Solution {
  public:
    long long squaresInChessBoard(long long N) {
        long long ans=(N*(N+1)*((2*N)+1))/6; // summation n^2;
        return ans;
    }
};