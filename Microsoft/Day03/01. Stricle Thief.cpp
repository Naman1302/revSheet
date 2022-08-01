class Solution{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        int loot=arr[0];
        int not_loot=0;
        for(int i=1;i<n;i++){
            int include = arr[i]+not_loot;
            int exclude = max(not_loot,loot);
            
            loot=include;
            not_loot=exclude;
        }
        return max(loot,not_loot);
    }
};