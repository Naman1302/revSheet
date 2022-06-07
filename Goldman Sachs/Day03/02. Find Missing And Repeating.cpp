/*
Idea : use the fact that numbers are in range 1 to N 
and their mod with N will be in range 0 to N-1 i.e. 
indices of arr.
*/
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int *ans= new int[2];

        sort(arr,arr+n);

        for(int i=0;i<n;i++){
             //go to arr[arr[i]] and make that element of index negative 
            if(arr[abs(arr[i])-1]<0){
                ans[0]=abs(arr[i]);// if we get any negative number that we get our repeating number
            }
            else
                arr[abs(arr[i])-1]=(-1)*arr[abs(arr[i])-1];
        }
        // after again traversal of array if we find any positive number 
        //then index of that number is our missing number
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                ans[1]=i+1;
                break;
            }
        }
        
        return ans;
    }
};