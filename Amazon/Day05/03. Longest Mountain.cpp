/*
Intuition:
We have already many 2-pass or 3-pass problems, like 821. Shortest Distance to a Character.
They have almost the same idea.
One forward pass and one backward pass.
Maybe another pass to get the final result, or you can merge it in one previous pass.

Explanation:
In this problem, we take one forward pass to count up hill length (to every point).
We take another backward pass to count down hill length (from every point).
Finally a pass to find max(up[i] + down[i] + 1) where up[i] and down[i] should be positives.
*/
//=============O(N) Space Solution=============
class SOlution{
    int longestMountain(vector<int> A) {
        int N = A.size(), res = 0;
        vector<int> up(N, 0), down(N, 0);
        for (int i = N - 2; i >= 0; --i) if (A[i] > A[i + 1]) down[i] = down[i + 1] + 1;
        for (int i = 0; i < N; ++i) {
            if (i > 0 && A[i] > A[i - 1]) up[i] = up[i - 1] + 1;
            if (up[i] && down[i]) res = max(res, up[i] + down[i] + 1);
        }
        return res;
    }
};
//=============================================

//=============O(1) Space Solution=============
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        int up=0,down=0,max_l=0;
        for(int i=1;i<n;i++){
            if(down && arr[i-1]<arr[i] || arr[i]==arr[i-1]){
                up=0;
                down=0;
            }
            down+=arr[i-1]>arr[i];
            up+=arr[i-1]<arr[i];
            if(up>0 && down>0)
               max_l=max(max_l,up+down+1); 
        }
        return max_l;
    }
};
//=============================================

