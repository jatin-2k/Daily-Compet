class Solution
{
    public:
    //Function to find maximum number of consecutive steps 
    //to gain an increase in altitude with each step.
    int maxStep(int arr[], int n)
    {
        int max=0;
        int here=0;
        
        for(int i=1; i<n; i++){
            
            if(arr[i]>arr[i-1]) here++;
            else{
                
                here=0;
            }
            if(max<here) max=here;
        }
       //Your code here
       return max;
    }
};