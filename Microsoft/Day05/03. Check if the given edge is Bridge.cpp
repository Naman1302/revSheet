/*
The logic behind this problem is that we keep adding the number till either we get our target of we hit 
greater than target...
Now, let's take some examples.
D = 1 (1 steps)
D = 2 (1 + 2) which is greater than 2 now we keep adding element till 
sum > target and (sum-target)%2 == 0) because (1 + 2 + 3) here 6 - 4 = 2 
so we will stop here... the logic here is if we turn +2 to -2 (1 -2 + 3) 
we will get 2...so we will be ultimately substracting 2*i from 
out sum....
      
D = 3 (1+2)  = 3
D = 4 (1 + 2 + 3) -->> -1 + 2 + 3 i.e 3
*/

class Solution{
public:
    
    int minSteps(int d){
        int steps=0,sum=0;
        while(1){
            sum+=steps;
            steps++;
            if(sum==d){
                return steps-1;
            }
            if(sum>d && (sum-d)%2==0)
                return steps-1;
        }
        return 0;
    }
};